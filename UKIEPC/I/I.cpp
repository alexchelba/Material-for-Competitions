#include<iostream>

using namespace std;

typedef long long ll;

#define MAXH 21
ll fact[MAXH];

void calc()
{
    fact[0] = 1;
    for(ll i = 1;i<MAXH;++i)
        fact[i] = fact[i-1] * i;
    return;
}

ll C(int n , int k)
{
    return fact[n] / (fact[n-k] * fact[k]);
}

ll pascal[MAXH][MAXH];

void build_pascal(int H , int top)
{
    ll min_coeff = 0;
    for(int i=1;i<H;++i)
        min_coeff += C(H-1,i);
    ll bot_l = top-min_coeff;
    pascal[H-1][0] = bot_l;
    for(int i=1;i<H;++i)
        pascal[H-1][i] = 1;
    for(int i=H-2;i>=0;--i)
    {
        for(int j=0;j<=i;++j)
            pascal[i][j] = pascal[i+1][j] + pascal[i+1][j+1];
    }
}

int main()
{
    calc();
    ll n,x;
    cin>>n>>x;
    ll min_coeff = 0;
    for(int i=0;i<n;++i)
        min_coeff += C(n-1,i);
    if(min_coeff > x)
    {
        cout<<"impossible\n";
        return 0;
    }
    build_pascal(n , x);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
            cout<<pascal[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}