#include <bits/stdc++.h>
#define inf 1LL*1000000000*1000000000
using namespace std;
ifstream f("dragoni.in");
ofstream g("dragoni.out");
int n,m,p,viz[810],s;
long long int dist[810][810],coada[810][810],d[810];
vector<pair<long long int,int> > v[810];
deque<pair<int,int> > q;
void df(int k)
{
    for(int i=0;i<v[k].size();i++)
    if(v[k][i].second<=d[1]&&!viz[v[k][i].first]) {viz[v[k][i].first]=1; df(v[k][i].first);}
}

int main()
{
    f>>p;
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>d[i];
    }
    if(p==1)
    {
        for(int i=1;i<=m;i++)
        {
            int x,y,d1;
            f>>x>>y>>d1;
            v[x].push_back({y,d1});
            v[y].push_back({x,d1});
        }
        viz[1]=1;
        df(1);
        int maxx=0;
        for(int i=1;i<=n;i++)
            if(viz[i]) if(d[i]>maxx) maxx=d[i];
        g<<maxx<<'\n';
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            int x,y,d1;
            f>>x>>y>>d1;
            v[x].push_back({d1,y});
            v[y].push_back({d1,x});
        }
        for(int i=1;i<=n;i++)
            sort(v[i].begin(),v[i].end());
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            dist[i][j]=inf;
        q.push_back(make_pair(1,1));
        coada[1][1]=1;
        dist[1][1]=0;
        long long sol=inf;
        while(q.size())
        {
            int lin=q.front().first;
            int col=q.front().second;
            coada[lin][col]=0;
            long long d1=dist[lin][col];
            q.pop_front();
            if(d[lin]>d[col]) col=lin;
            for(vector<pair<long long,int> >::iterator it=v[lin].begin();it!=v[lin].end()&&d[col]>=it->first;it++)
            {
                if(d1+it->first>=sol||d1+it->first>=dist[it->second][col]) continue;
                if(it->second==n)
                {
                    sol=d1+it->first;
                    continue;
                }
                dist[it->second][col]=d1+it->first;
                if(!coada[it->second][col])
                {
                    coada[it->second][col]=1;
                    q.push_back(make_pair(it->second,col));
                }
            }
        }
        g<<sol<<'\n';
    }
    return 0;
}
