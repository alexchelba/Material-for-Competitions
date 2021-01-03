#include<iostream>
#include<algorithm>
#include<vector>

#define l 2*pos+1
#define r 2*pos+2
#define mid (start+stop)/2
#define MAXN 100005
using namespace std;

int st[MAXN*3];

struct coin
{
    int t , w;
};

struct slot
{
    int t , w , id;
};

bool comp_coin(coin a , coin b)
{
    return a.t < b.t;
}

bool comp_slot(slot a , slot b)
{
    return a.t < b.t;
}

int s , c;
coin coins[MAXN];
slot slots[MAXN];

void build(int pos , int start , int stop)
{
    if(start == stop)
    {
        st[pos] = MAXN+69;
        return;
    }
    build(l,start,mid);
    build(r,mid+1,stop);
    st[pos] = MAXN+69;
    return;
}

void update(int pos , int start , int stop , int i , int x)
{
    if(start == stop)
    {
        st[pos] = min(st[pos] , x);
        return;
    }
    if(i<=mid)
        update(l,start,mid,i,x);
    else
        update(r,mid+1,stop,i,x);
    st[pos] = min(st[l] , st[r]);
    return;
}

int query(int pos , int start , int stop , int i , int j)
{
    if(start >= i && stop <= j)
        return st[pos];
    int L = MAXN+69 , R = MAXN+69;
    if(i <= mid)
        L = query(l , start , mid , i , j);
    if(j >= mid+1)
        R = query(r , mid+1 , stop , i , j);
    return min(L ,R);
}


int main()
{
    cin>>s;
    for(int i=0;i<s;++i)
    {
        cin>>slots[i].t>>slots[i].w;
        slots[i].id = i+1;
    }
    
    cin>>c;
    for(int i=0;i<c;++i)
    {
        cin>>coins[i].t>>coins[i].w;
    }

    sort(slots , slots + s , comp_slot);
    sort(coins , coins + c , comp_coin);

    build(0,0,MAXN-1);

    long long sum = 0;
    int j = s-1;
    for(int i = c-1;i>=0;--i)
    {
        while(j >= 0 && coins[i].t <= slots[j].t)
        {
            update(0,0,MAXN-1,slots[j].w,slots[j].id);
            j--;
        }
        sum += (long long)query(0,0,MAXN-1,0,coins[i].w);
    }
    cout<<sum<<"\n";
    return 0;
}