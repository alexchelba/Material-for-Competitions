/** /// ciclu eulerian 10 pct X-(((((((
#include <bits/stdc++.h>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
unsigned int n,m,viz[501001];
vector<int> v[501001];
void df(int k)
{
    viz[k]=1;
    for(int i=0;i<v[k].size();i++)
        if(viz[v[k][i]]==0) df(v[k][i]);
}
int conex()
{
    df(1);
    for(int i=1;i<=n;i++)
        if(viz[i]==0) return 0;
    for(int i=1;i<=n;i++)
        if(v[i].size()%2==1) {g<<"-1"<<'\n'; return 0;}
    return 1;
}
void ciclu(int k)
{
    if(!v[k].size()) return ;
    int maxx=0;
    int nmax=0;
    g<<k<<" ";
    for(int i=0;i<v[k].size();i++)
    {
        if(v[v[k][i]].size()>maxx)
        {
            maxx=v[v[k][i]].size();
            nmax=i+1;
        }
    }
    g<<nmax<<" "<<v[k][nmax-1]<<'\n';
    if(nmax)
    {
        int w=v[k][nmax-1];
        v[v[k][nmax-1]].erase(find(v[v[k][nmax-1]].begin(),v[v[k][nmax-1]].end(),k));
        v[k].erase(find(v[k].begin(),v[k].end(),w));
        ciclu(w);
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(conex()) ciclu(1); else g<<"-1"<<'\n';
    return 0;
}
**/

/**
/// ciclu hamiltonian de cost minim
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("hamilton.in");
ofstream g("hamilton.out");
int s,n,m,ult,gasit,viz[201],x[201],d[201];
vector<pair<int,int> > v[201];
queue<int> q;
bool isEqual(const std::pair<int, int> &element)
{
    return element.first==s;
}
int bun(int k)
{
    s=x[k-1];
    if(k>1) if(find_if(v[x[k]].begin(),v[x[k]].end(),isEqual)==v[x[k]].end()) return 0;
    s=x[n];
    if(k==n) if(find_if(v[x[1]].begin(),v[x[1]].end(),isEqual)==v[x[1]].end()) return 0;
    return 1;
}
void backt(int k)
{
    if(gasit) return ;
    for(int i=0;i<n;i++)
    if(!viz[i])
    {
        g<<i<<" "<<bun(k)<<'\n';
        x[k]=i; viz[i]=1;
        if(bun(k))
            if(k==n) gasit=1;
                else backt(k+1);
        viz[i]=0;
    }
}
int nul()
{
    for(int i=0;i<n;i++)
        if(!viz[i]) return 1;
    return 0;
}
void ciclu(int k)
{
    memset(d,inf,sizeof(d));
    q.push(k);
    while(!q.empty())
    {
        int w=q.front();
        ult=w;
        q.pop();
        for(int i=0;i<v[w].size();i++)
        if(!viz[v[w][i].first]&&d[v[w][i].first]>d[w]+v[w][i].second)
        {
            viz[v[w][i].first]=1;
            d[v[w][i].first]=d[w]+v[w][i].second;
            q.push(v[w][i].first);
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        v[x].push_back({y,z});
    }
    backt(1);
    if(gasit)
    {
        for(int i=0;i<n;i++)
        {
            memset(viz,0,sizeof(viz));
            ciclu(i);
            if(ult==i&&!nul()) g<<d[i]<<'\n';
        }
    }
    return 0;
}
**/

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
5
