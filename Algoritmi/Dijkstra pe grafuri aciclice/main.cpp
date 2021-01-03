#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
stack<int> s;
int n,m,x,y,v[500001],k,d[500001],pinf=1000000000;
bool viz[500001];

struct nod{
    int dist,info;
    nod *next;
}*lista[50001];

void citire()
{
    f>>n>>m;
    int i,x,y,z;
    for (i = 1; i <= m; i++)
    {
        f>>x>>y>>z;
        nod *p=new nod;
        p->next=lista[x];
        p->info=y;
        p->dist=z;
        lista[x]=p;
    }
}

void DF(int k)
{
    nod *p;
    viz[k]=true;
    for(p=lista[k];p!=NULL;p=p->next)
        if(!viz[p->info])
            DF(p->info);
    s.push(k);
}

int main()
{
    citire();
    for(int i=2;i<=n;i++)
        d[i]=pinf;
    for(int i=1;i<=n;i++)
        if(!viz[i])
            DF(i);

    while(!s.empty())
    {
        //g<<s.top()<<' ';
        int k=s.top();
        s.pop();
        nod *p=lista[k];
        while(p)
        {
            if(d[p->info]>d[k]+p->dist)
                d[p->info]=d[k]+p->dist;
            p=p->next;
        }
    }
    for(int i=1;i<=n;i++)
        g<<d[i]<<" ";
    f.close();
    g.close();
    return 0;
}
