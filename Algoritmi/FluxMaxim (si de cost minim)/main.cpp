/// 100 pct + 70 pct
#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
/**
int n,m,s,d;
vector<int> v[1001];
int flux,c[1001][1001],t[1001];
queue<int> q;
int bf()
{
    memset(t,0,sizeof(t));
    t[1]=1;
    q.push(s);
    while(q.size())
    {
        int i=q.front();
        q.pop();
        for(auto j: v[i])
        {
            if(t[j]==0&&c[i][j]>0)
            {
                t[j]=i;
                if(j!=d) q.push(j);
            }
        }
    }
    if(t[d]) return 1;
    return 0;
}
int flux_maxim()
{
    while(bf())
    {
        for(auto i: v[d])
        if(t[i])
        {
            t[d]=i;
            int minn=2000000000;
            i=d;
            while(i!=s)
            {
                minn=min(minn,c[t[i]][i]);
                i=t[i];
            }
            i=d;
            while(i!=s)
            {
                c[t[i]][i]-=minn;
                c[i][t[i]]+=minn;
                i=t[i];
            }
            flux+=minn;
        }
    }
    return flux;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,ci;
        f>>x>>y>>ci;
        v[x].push_back(y);
        v[y].push_back(x);
        c[x][y]=ci;
    }
    s=1; d=n;
    g<<flux_maxim()<<'\n';
    return 0;
}
**/

int drum,n,m,s,d,dist[360],viz[360],c[360][360],t[360];
vector<pair<int,int> > v[360];
queue<int> q;
int bellmanford()
{
    for(int i=1;i<=n;i++) {dist[i]=inf; t[i]=-1;}
    int ok=1;
    dist[s]=0;
    q.push(s);
    viz[s]=1;
    while(q.size())
    {
        int w=q.front();
        q.pop();
        for(auto it: v[w])
        if(c[w][it.first]&&dist[it.first]>dist[w]+it.second)
        {
            dist[it.first]=dist[w]+it.second;
            t[it.first]=w;
            if(!viz[it.first])
            {
                q.push(it.first);
                viz[it.first]=1;
            }
        }
        viz[w]=0;
    }
    if(dist[d]!=inf)
    {
        int minn=inf;
        drum=1;
        int i=d;
        while(i!=s)
        {
            minn=min(minn,c[t[i]][i]);
            i=t[i];
        }
        i=d;
        while(i!=s)
        {
            c[t[i]][i]-=minn;
            c[i][t[i]]+=minn;
            i=t[i];
        }
        return minn*dist[d];
    }
    return 0;
}
long long flux()
{
    long long rez=0;
    drum=1;
    while(drum)
    {
        drum=0;
        rez+=bellmanford();
    }
    return rez;
}
int main()
{
    f>>n>>m>>s>>d;
    for(int i=1;i<=m;i++)
    {
        int x,y,ci,cost;
        f>>x>>y>>ci>>cost;
        v[x].push_back({y,cost});
        v[y].push_back({x,-cost});
        c[x][y]=ci;
    }
    g<<flux()<<'\n';
    return 0;
}
