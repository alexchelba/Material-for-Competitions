#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
int d[50001],n,m,x,y,c;
vector<pair<int, int> > v[50001];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
void dijkstra(int nod){
    memset(d,inf,sizeof(d));
    ///memset(t,nod,sizeof(t));
    q.push({0,nod});
    d[nod]=0;
    ///t[nod]=0;
    while(!q.empty()){
        int w = q.top().second;
        int d1 = q.top().first;
        q.pop();
        if(d1==d[w]){
            for(int i=0;i<v[w].size();i++){
                if(d[v[w][i].first]>d[w]+v[w][i].second){
                    d[v[w][i].first]=d[w]+v[w][i].second;
                    q.push({d[v[w][i].first],v[w][i].first});
                }
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(d[i]==inf) d[i]=0;
        g<<d[i]<<" ";
    }
    g<<'\n';
    /**
    for(int i=1;i<=n;i++)
        g<<t[i]<<" ";
    g<<'\n';
    **/
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>c;
        v[x].push_back({y,c});
    }
    dijkstra(1);
    return 0;
}
