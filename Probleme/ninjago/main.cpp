#include <bits/stdc++.h>
using namespace std;
ifstream f("ninjago.in");
ofstream g("ninjago.out");
struct muchie
{
    int x,y,c,e;
    friend bool operator<(muchie a, muchie b)
    {
        return a.c<b.c;
    }
};
int n,m,p,viz[31210],nrp,t[31210],total;
vector<int> g1[31210];
vector<muchie> graf,sol;
void dfs(int k)
{
    viz[k]=1; nrp++;
    for(int i=0;i<g1[k].size();i++)
        if(viz[g1[k][i]]==0) {dfs(g1[k][i]);}
}
int compr(int v)
{
    if(t[v]==v) return v;
    t[v]=compr(t[v]);
    return t[v];
}
void apm()
{
    muchie w;
    sort(graf.begin(),graf.end(),less<muchie>());
    for(int i=0;i<graf.size();i++)
    {
        int a=graf[i].x, b=graf[i].y;
        int x=compr(a), y=compr(b);
        if(x!=y)
        {
            t[x]=y;
            total+=graf[i].c%625;
            sol.push_back(graf[i]);
        }
    }
}
int main()
{
    f>>p;
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        muchie w;
        string s;
        f>>w.x>>w.y>>s;
        int cost=0, ok=1, nreuri=0, p=1;
        for(int j=0;j<s.length();j++, p=p*5)
        if(s[j]=='E') { ok=0; nreuri++; cost+=625;}
        else {cost+=p*(s[j]-'A'+1);}
        w.e=nreuri;
        w.c=cost;
        graf.push_back(w);
        if(ok)
        {
            g1[w.x].push_back(w.y);
            g1[w.y].push_back(w.x);
        }
    }
    if(p==1)
    {
        dfs(1);
        g<<nrp<<'\n';
    }
    else
    {
        for(int i=1;i<=n;i++)
            t[i]=i;
        apm();
        if(p==2)
        {
            int nre=0, nraj=0;
            for(int i=0;i<sol.size();i++)
            if(sol[i].c>=625)
            {
                nraj++;
                nre+=sol[i].e;
            }
            g<<nraj<<'\n'<<nre<<'\n';
        }
        else g<<total<<'\n';
    }
    return 0;
}
