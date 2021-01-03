#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("posta2.in");
ofstream g("posta2.out");
long long n,m,dir[100001],tax[100001],marc[100001],sol=2000000000000000000;
vector<pair<int, int> > v[100001];
long long df(int k, int rad)
{
    long long nr=0,val=0;
    for(int i=0;i<v[k].size();i++)
        if(v[k][i].first!=rad)
        {
            long long cur=df(v[k][i].first,k);
            if(cur||marc[v[k][i].first])
            {
                val+=cur+2*v[k][i].second;
                nr++;
            }
        }
    dir[k]=nr;
    return val;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y,cost;
        f>>x>>y>>cost;
        v[x].push_back({y,cost});
        v[y].push_back({x,cost});
    }
    for(int i=1;i<=n;i++)
        f>>tax[i];
    for(int i=1;i<=m;i++)
    {
        int x;
        f>>x;
        marc[x]=1;
    }
    if(m==0) {g<<0<<'\n'; return 0;}
    long long dist=0, taxa=0;
    for(int i=1;i<=n;i++)
    if(marc[i])
    {
        dist=df(i,0);
        dir[i]--;
        break;
    }
    for(int i=1;i<=n;i++)
        taxa+=tax[i]*dir[i];
    for(int i=1;i<=n;i++)
        sol=min(sol, dist+taxa-(tax[i]*dir[i]));
    g<<sol<<'\n';
    return 0;
}
