#include <bits/stdc++.h>
#define inf 2000000000000000000
using namespace std;
ifstream f("pikachu.in");
ofstream g("pikachu.out");
int n,k;
struct interval
{
    long long maxim,minim,nrz;
};
interval arb[300001];
long long minn;
void update(int po, int st, int dr, int p, long long val)
{
    if(st>=p&&p>=dr)
    {
        arb[po].maxim=val;
        arb[po].minim=val;
        arb[po].nrz=0;
        return;
    }
    int mij=(st+dr)/2;
    if(p<=mij) update(2*po,st,mij,p,val);
    else update(2*po+1,mij+1,dr,p,val);
    long long max1=max(arb[2*po].nrz,arb[2*po+1].nrz);
    if(arb[2*po].minim<=arb[2*po+1].minim&&arb[2*po+1].maxim<=arb[2*po].maxim) arb[po].nrz=arb[2*po].nrz;
    else
    if(arb[2*po+1].minim<=arb[2*po].minim&&arb[2*po].maxim<=arb[2*po+1].maxim) arb[po].nrz=arb[2*po+1].nrz;
    else if(max1==0) arb[po].nrz=abs(arb[2*po+1].maxim-arb[2*po].maxim);
    else arb[po].nrz=max1+abs(arb[2*po+1].maxim-arb[2*po].maxim)+abs(arb[2*po+1].minim-arb[2*po].minim);
    arb[po].maxim=max(arb[2*po+1].maxim,arb[2*po].maxim);
    arb[po].minim=min(arb[2*po+1].minim,arb[2*po].minim);
}
long long interogare(int po, int st, int dr, int a, int b)
{
    if(a<=st&&dr<=b)
    {
        return arb[po].nrz;
    }
    int mij=(st+dr)/2;
    long long x1=0,x2=0;
    if(a<=mij) x1=interogare(2*po,st,mij,a,b);
    if(b>mij) x2=interogare(2*po+1,mij+1,dr,a,b);
    g<<"m "<<x1<<" "<<x2<<'\n';
    return x1+x2;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        f>>x;
        update(1,1,n,i,x);
    }
    /**
    int k=1;
    while(k<=2*n)
    {
        g<<arb[k].maxim<<" "<<arb[k].minim<<" "<<arb[k].nrz<<'\n';
        k++;
    }**/
    long long minn=inf;
    for(int i=1;i+k-1<=n;i++)
    {
        long long pv=interogare(1,1,n,i,i+k-1);
        g<<pv<<'\n';
        if(pv<minn) minn=pv;
    }
    g<<minn<<'\n';
    return 0;
}
