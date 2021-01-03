#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("graf.in");
ofstream g("graf.out");
int n,m,nr2,x,y,nr,minn=inf,ok,viz[7550],distx[7550],disty[7550],cara1[7550],cara2[7550];
vector<int> v[7550];
deque<int> q1,q2;
vector<int> sol;
void bfs1(int k)
{
    if(q1.empty()) return ;
        for(int i=0;i<v[k].size();i++)
        if(distx[v[k][i]]==0)
        {
            distx[v[k][i]]=distx[k]+1;
            q1.push_back(v[k][i]);
        }
        q1.pop_front();
        bfs1(q1.front());
}
void bfs2(int k)
{
    if(q2.empty()) return ;
    for(int i=0;i<v[k].size();i++)
            if(disty[v[k][i]]==0)
            {
                disty[v[k][i]]=disty[k]+1;
                q2.push_back(v[k][i]);
            }
        q2.pop_front();
        bfs2(q2.front());
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(find(v[x].begin(),v[x].end(),y)!=v[x].end()) {g<<"2"<<'\n'<<x<<" "<<y<<'\n'; return 0;}
    memset(distx,0,sizeof(distx));
    memset(disty,0,sizeof(disty));

    distx[x]=1;
    q1.push_back(x);
    bfs1(x);

    disty[y]=1;
    q2.push_back(y);
    bfs2(y);

    for(int i=1;i<=n;i++)
        distx[i]--;
    for(int i=1;i<=n;i++)
        disty[i]--;
    /**
    for(int i=1;i<=n;i++)
        g<<distx[i]<<" ";
    g<<'\n';
    for(int i=1;i<=n;i++)
        g<<disty[i]<<" ";
    g<<'\n';
    **/
    int drum=distx[y];
    for(int i=1;i<=n;i++)
        if(distx[i]+disty[i]==drum) {viz[i]++;}
    for(int i=1;i<=n;i++)
    {
        if(viz[i])
        {
            cara1[distx[i]]++;
            cara2[disty[i]]++;
        }
    }
    /**
    for(int i=1;i<=n;i++)
        g<<distx[i]<<" "<<cara1[distx[i]]<<'\n'<<disty[i]<<" "<<cara2[disty[i]]<<'\n';
    **/
    for(int i=1;i<=n;i++)
    if(viz[i]&&cara1[distx[i]]==1&&cara2[disty[i]]==1) {nr++; sol.push_back(i);}
    g<<nr<<'\n';
    for(int i=0;i<sol.size();i++)
        g<<sol[i]<<" ";
    return 0;
}
