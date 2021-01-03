#include<bits/stdc++.h>
using namespace std;
#define MAX 50010
#define inf 1000000000
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
vector <pair<int, int> > G[MAX];
priority_queue <pair<int, int> > PQ;
int dist[MAX], viz[MAX];
int main()
{
    int n, m, x, y, c, i, nod;
    f>>n>>m;
    while(m--)
    {
        f>>x>>y>>c;
        G[x].push_back(make_pair(y, c));
    }
    dist[1]=0;
    for(i=2 ;i<=n ;i++)
    {
        dist[i]=inf;
    }
    PQ.push(make_pair(0, 1));
    while(PQ.size())
    {
        pair<int, int> aux=PQ.top();
        PQ.pop();
        nod=aux.second;
        if(viz[nod])
            continue;
        viz[nod] = 1;
        ///for(vector<int>::iterator it=G[nod].begin();it<G[nod].end();it++)
            for(auto it : G[nod])
            if(dist[nod] + it.second < dist[it.first])
            {
                dist[it.first] = dist[nod] + it.second;
                PQ.push(make_pair(-dist[it.first], it.first));
            }
    }

    for(i = 2 ; i <= n ; i++)
    {
        if(dist[i]==inf)
            dist[i]=0;
        g<<dist[i]<<" ";
    }
    g<<'\n';


}
