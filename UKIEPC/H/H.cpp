#include<iostream>
#include<algorithm>

#define MAXN 100005
using namespace std;

struct variable
{
    int id;
    long long count;
    variable(int id_c ,int count_c)
    {
        id = id_c;
        count = count_c;
    }

    variable()
    {

    }
};

variable vs[MAXN];
int instr[MAXN];
int instr_cnt , n;

bool comp(variable a , variable b)
{
    return a.count >= b.count;
}

int main()
{
    cin>>n>>instr_cnt;
    for(int i=0;i<instr_cnt;++i)
    {
        cin>>instr[i];
        --instr[i];
    }
    
    for(int i=0;i<n;++i)
    {
        vs[i] = variable(i,0);
    }

    for(int i=1;i<instr_cnt;++i)
    {
        vs[instr[i]].count++;
        swap(vs[instr[i-1]] , vs[instr[i]]);
    }

    sort(vs , vs+n , comp);

    long long sum = 0;
    for(long long i=0;i<n-1;++i)
        sum += vs[i].count * (long long)(i+1);
    cout<<sum<<"\n";
    for(int i=0;i<n-1;++i)
        cout<<vs[i].id+1<<" ";
    cout<<"\n";
    return 0;
}