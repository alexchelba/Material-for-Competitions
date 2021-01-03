#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("catun.in");
ofstream g("catun.out");
int n,m,k,dist_c[36005],fort[36005];
vector<pair<int, int> > v[36005];
priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
void dijkstra(){
    while(q.size()){
        int w=q.top().second;
        int c=q.top().first;
        q.pop();
        for(int i=0;i<v[w].size();i++)
            if((dist_c[v[w][i].first]>c+v[w][i].second)||(dist_c[v[w][i].first]==c+v[w][i].second&&fort[v[w][i].first]>fort[w])){
                dist_c[v[w][i].first]=c+v[w][i].second;
                fort[v[w][i].first]=fort[w];
                q.push({dist_c[v[w][i].first],v[w][i].first});
            }
    }
    for(int i=1;i<=n;i++)
        if(fort[i]==i||fort[i]==inf) g<<"0 ";
        else g<<fort[i]<<" ";
}
int main()
{
    memset(dist_c, inf, sizeof(dist_c));
    memset(fort, inf, sizeof(fort));
    f>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x;
        f>>x;
        q.push({0,x});
        dist_c[x]=0;
        fort[x]=x;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        f>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dijkstra();
    return 0;
}
