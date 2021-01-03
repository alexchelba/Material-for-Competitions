#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,x,q;
long long s1,s2,arb[300000],lazy[300000];
void updaterange(int po, int st, int dr, int a, int b, int val)
{
    if(lazy[po])
    {
        arb[po]+=(dr-st+1)*lazy[po];
        if(st!=dr)
        {
            lazy[2*po]+=lazy[po];
            lazy[2*po+1]+=lazy[po];
        }
        lazy[po]=0;
    }
    if(st>dr||st>b||dr<a) return;
    if(a<=st&&dr<=b)
    {
        arb[po]+=(dr-st+1)*val;
        if(st!=dr)
        {
            lazy[2*po]+=val;
            lazy[2*po+1]+=val;
        }
        return;
    }
    int mij=(st+dr)/2;
    updaterange(2*po,st,mij,a,b,val);
    updaterange(2*po+1,mij+1,dr,a,b,val);
    arb[po]=arb[2*po]+arb[2*po+1];
}
int interogrange(int po, int st, int dr, int a, int b)
{
    g<<st<<" "<<dr<<" "<<a<<" "<<b<<'\n';
    ///if(st>dr||st>b||dr<a) return 0;
    if(lazy[po])
    {
        arb[po]+=(dr-st+1)*lazy[po];
        if(st!=dr)
        {
            lazy[2*po]+=lazy[po];
            lazy[2*po+1]+=lazy[po];
        }
        lazy[po]=0;
    }
    if(a<=st&&dr<=b) return arb[po];
    int mij=(st+dr)/2, p1=0, p2=0;
    if(a<=mij) p1=interogrange(2*po,st,mij,a,b);
    if(b>mij) p2=interogrange(2*po+1,mij+1,dr,a,b);
    return p1+p2;
}
void update(int po, int st, int dr, int p, int val)
{
    if(st>=p&&p>=dr) {arb[po]=val; return ;}
    int mij=(st+dr)/2;
    if(p<=mij) update(2*po,st,mij,p,val);
    else update(2*po+1,mij+1,dr,p,val);
    arb[po]=arb[2*po]+arb[2*po+1];
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        update(1,1,n,i,x);
    }
    f>>q;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        f>>x>>y;
        g<<interogrange(1,1,n,x,y)<<'\n';
        updaterange(1,1,n,x,y,1);
    }
    return 0;
}
