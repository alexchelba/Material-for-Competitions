#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("distante.in");
ofstream g("distante.out");
int t,n,m,s,dist_o[50005],dist_c[50005];
vector<pair<int, int> > v[50001];
priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
void dijkstra(int nod){
    memset(dist_c, inf, sizeof(dist_c));
    dist_c[nod]=0;
    q.push({0, nod});
    while(q.size()){
        int w=q.top().second;
        int c=q.top().first;
        q.pop();
        if(c==dist_c[w]){
            for(int i=0;i<v[w].size();i++)
            if(dist_c[v[w][i].first]>c+v[w][i].second){
                dist_c[v[w][i].first]=c+v[w][i].second;
                q.push({dist_c[v[w][i].first],v[w][i].first});
            }
        }
    }
    int ok=1;
    for(int i=1;i<=n&&ok;i++)
        if(dist_c[i]!=dist_o[i]) ok=0;
    if(ok) g<<"DA"<<'\n';
    else g<<"NU"<<'\n';
}
int main()
{
    f>>t;
    for(int q=1;q<=t;q++){
        f>>n>>m>>s;
        for(int i=1;i<=n;i++)
            f>>dist_o[i];
        for(int i=1;i<=m;i++){
            int a,b,c;
            f>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        dijkstra(s);
        for(int i=1;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
