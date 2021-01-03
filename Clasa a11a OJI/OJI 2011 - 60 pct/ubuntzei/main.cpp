#include <iostream>
#include <fstream>
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
struct nod{
    int nr,val;
    nod *urm;
};
nod *a[2001],*p,*prim,*ultim;
int n,m,k,d[2001],prieten[2001],L[20][2001],mini=1000000000,x[2001],viz[2001];

void citire()
{
    f>>n>>m>>k;
    if(k>0)
        for(int i=1;i<=k;i++)
            f>>prieten[i];
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        p=new nod;
        p->nr=y;
        p->val=z;
        p->urm=0;
        p->urm=a[x];
        a[x]=p;

        p=new nod;
        p->nr=x;
        p->val=z;
        p->urm=0;
        p->urm=a[y];
        a[y]=p;
    }
}

void dijkstra(int v1)
{
    for(int i=1;i<=n;i++)
        d[i]=99999999;
    d[v1]=0;
    prim=new nod;
    prim->nr=v1;
    prim->urm=NULL;
    ultim=prim;
    while(prim)
    {
        int nod1=prim->nr;
        nod *q=a[nod1];
        while(q)
        {
            if(d[q->nr]>d[nod1]+q->val)
            {
                d[q->nr]=d[nod1]+q->val;
                p=new nod;
                p->nr=q->nr;
                p->urm=NULL;
                ultim->urm=p;
                ultim=p;
            }
            q=q->urm;
        }
        p=prim;
        prim=prim->urm;
        delete p;
    }
}

int sum()
{
    int s=L[1][prieten[x[1]]]+L[x[k+1]][n];
    if(k>=2)
        for(int i=2;i<k+1;i++)
            s+=L[x[i]][prieten[x[i+1]]];
    return s;
}

void backt(int j)
{
    for(int i=2;i<=k+1;i++)
        if(!viz[i])
        {
            x[j]=i;
            viz[i]=1;
            if(j<k)
                backt(j+1);
            else
            {
                int s=sum();
                if(mini>s && s)
                    mini=s;
            }
            viz[i]=0;
        }
}

int main()
{
    citire();
    dijkstra(1);
    for(int j=1;j<=n;j++)
        L[1][j]=d[j];
    dijkstra(n);
    for(int j=1;j<=n;j++)
        L[k+2][j]=d[j];
    for(int i=1;i<=k;i++)
    {
        dijkstra(prieten[i]);
        for(int j=1;j<=n;j++)
            L[i+1][j]=d[j];
    }
    if(k>0)
        {x[1]=1; x[k+2]=n; backt(2); g<<mini;}
    else
        g<<L[1][n];
    return 0;
}
