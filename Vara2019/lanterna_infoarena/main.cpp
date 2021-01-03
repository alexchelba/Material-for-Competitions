#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("lanterna.in");
ofstream g("lanterna.out");
vector<pair<int, pair<int,int> > > v[55];
queue<pair<int,int> > q;
int d[55][1005],n,m,a[55],viz[55],k;
void bellman_ford(int nod){
    q.push({nod,0});
    for(int i=1;i<=n;i++) memset(d[i],inf,sizeof(d[i]));
    memset(viz,0,sizeof(viz));
    d[nod][0]=0;
    while(q.size()){
        int w=q.front().first;
        int co = q.front().second;
        q.pop();
        if(++viz[w]==n) break;
        for(int i=0;i<v[w].size();i++){
            int moo =d[w][co] + v[w][i].second.second;
            if(moo<=k){
                q.push({v[w][i].second.first, moo});
                if(a[v[w][i].second.first]) q.push({v[w][i].second.first, 0});
                if(d[v[w][i].second.first][moo]>d[w][co]+v[w][i].first){
                    d[v[w][i].second.first][moo] = d[w][co]+v[w][i].first;
                    if(a[v[w][i].second.first]) {d[v[w][i].second.first][0]=d[v[w][i].second.first][moo];}
                }/**
                    else
                if(d[v[w][i].second.first][moo]==d[w][co]+v[w][i].first){
                    if(d[v[w][i].second.first][moo] > lanterna[w]+v[w][i].second.second){
                        lanterna[v[w][i].second.first] = lanterna[w] + v[w][i].second.second;
                        if(a[v[w][i].second.first]) {d[v[w][i].second.first][0]= d[v[w][i].second.first][lanterna[v[w][i].second.first]]; lanterna[v[w][i].second.first]=0;}
                    }
                }
                **/
            }
        }
    }
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;i++)
        f>>a[i];
    f>>m;
    for(int i=1;i<=m;i++){
        int x,y,c,w;
        f>>x>>y>>c>>w;
        v[x].push_back({c,{y,w}});
        v[y].push_back({c,{x,w}});
    }
    bellman_ford(1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            g<<d[i][j]<<" ";
        }
        g<<'\n';
    }
    return 0;
}
