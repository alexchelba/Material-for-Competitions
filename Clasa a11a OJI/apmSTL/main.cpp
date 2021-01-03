#include <bits/stdc++.h>
#define nmax 200010
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
int n,m,i,j,t[nmax],x,y,c,cost,a,b;
pair<int, pair<int, int> > M[2*nmax];
vector<pair<int, int> > sol;
int compr(int v)
{
    if(t[v]==v)
        return v;
    t[v]=compr(t[v]);
    return t[v];
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        M[i]={c,{x,y}};
    }
    sort(M+1,M+m+1);
    for(i=1;i<=n;i++)
        t[i]=i;
    i=1;
    j=n-1;
    while(j)
    {
        a=M[i].second.first;
        b=M[i].second.second;
        x=compr(a);
        y=compr(b);
        if(x!=y)
        {
            t[x]=y;
            cost+=M[i].first;
            sol.push_back({a,b});
            j--;
        }
        i++;
    }
    g<<cost<<'\n'<<n-1<<'\n';
    for(vector<pair<int,int> >:: iterator it=sol.begin();it!=sol.end();it++)
        g<<it->first<<" "<<it->second<<'\n';
    return 0;
}
