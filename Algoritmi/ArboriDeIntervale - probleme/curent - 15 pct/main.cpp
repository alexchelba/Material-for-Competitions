#include <bits/stdc++.h>
using namespace std;
ifstream f("curent.in");
ofstream g("curent.out");
struct tupla
{
    mutable int ziua, casa, nr, rez;
};
bool operator<(const tupla &a, const tupla &b)
{
    return (a.ziua<b.ziua)||(a.ziua==b.ziua&&a.casa<b.casa)||
    ((a.ziua==b.ziua&&a.casa==b.casa&&a.nr<b.nr));
}
int n,m,p[100020],ars[100020],tata[100020];
vector<int> v[100020];
multiset<tupla> caz;
queue<int> q;
void bf(int k, int marc, int t)
{
    q.pop();
    for(int i=0;i<v[k].size();i++)
    {
        if(!ars[v[k][i]])
        {
            q.push(v[k][i]);
            tata[v[k][i]]+=t;
            if(t<0&&!tata[v[k][i]]) p[v[k][i]]=marc;
            else if(t>0) p[v[k][i]]=marc;
        }
    }
    if(q.size()) bf(q.front(),marc,t);
}
int main()
{
    f>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x;
        f>>x;
        v[x].push_back(i+1);
    }
    f>>m;
    for(int i=1;i<=m;i++)
    {
        int zi,cs,num;
        f>>zi>>cs>>num;
        ///g<<zi<<" "<<cs<<" "<<num<<'\n';
        caz.insert({zi,cs,num,0});
    }
    /**
    set<tupla>::iterator it;
    for(it=caz.begin();it!=caz.end();it++)
            g<<it->ziua<<" "<<it->casa<<" "<<it->nr<<'\n';
    **/
    int intrebari;
    f>>intrebari;
    for(int i=1;i<=intrebari;i++)
    {
        int zi;
        f>>zi;
        set<tupla>::iterator it=caz.begin();
        while(zi>=it->ziua)
        {
            if(!it->rez)
            {
                it->rez=1;
                if(it->nr==0)
                {
                    if(p[it->casa]<2)
                    {
                        p[it->casa]=2;
                        ars[it->casa]=1;
                        q.push(it->casa);
                        bf(it->casa,1,1);
                    }
                }
                else
                {
                    if(p[it->casa]==2)
                    {
                        p[it->casa]=0;
                        if(tata[it->casa]) p[it->casa]=1;
                        ars[it->casa]=0;
                        q.push(it->casa);
                        bf(it->casa,0,-1);
                    }
                }
                ///g<<it->ziua<<'\n';
            }
            it++;
            if(it==caz.end()) break;
        }
        int nr=0;
        for(int j=1;j<=n;j++)
            g<<tata[j]<<" ";
        g<<'\n';
        for(int j=1;j<=n;j++)
            {
                g<<p[j]<<" ";
                if(p[j]==0) nr++;
            }
        g<<'\n';
        g<<nr<<'\n';
    }
    return 0;
}
