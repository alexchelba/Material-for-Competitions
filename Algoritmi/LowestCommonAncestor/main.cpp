#include <bits/stdc++.h>
using namespace std;
#define NMAX 100002
#define INF 0x3f3f3f3f
ifstream f("lca.in");
ofstream g("lca.out");
long int aint[NMAX*3];
long int n,m,mx;
void update(long int nod, long int st, long int dr, long int poz, long int val)
{
if (st==dr) aint[nod]=val;
    else
    {
        long int mid=(st+dr)/2;

        if (poz<=mid) update(nod*2,st,mid,poz,val);
            else update(nod*2+1,mid+1,dr,poz,val);
        aint[nod]=min(aint[nod*2],aint[nod*2+1]);
    }

}

void query(long int nod, long int st, long int dr, long int a, long int b)
{
    if (a<=st&&dr<=b) mx=min(mx,aint[nod]);
        else
        {
            long int mid=(st+dr)/2;

            if (a<=mid) query(nod*2,st,mid,a,b);
            if (b>mid) query(nod*2+1,mid+1,dr,a,b);
        }
}

int main()
{
    long int i,x,y,k;
    f>>n>>m;
    for (i=1;i<=n;i++)
        {
            f>>x;
            update(1,1,n,i,x);
        }
    for(int i=1;i<=n;i++)
        g<<aint[i]<<" ";
    g<<'\n';
    for (i=1;i<=m;i++)
        {
            f>>x>>y;
            mx=INF;
            query(1,1,n,x,y);
            g<<mx<<'\n';

        }
    return 0;
}
