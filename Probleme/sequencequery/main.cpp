#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("sequencequery.in");
ofstream g("sequencequery.out");
struct interval
{
    int  stn,drt;
    long long sumstn, sumdrt, summij, sumtot;
};
interval arb[300001];
int n,q,nr,x,y;
long long sol,aux;
char c;
void update(int po, int st, int dr, int p, int val)
{
    if(st>=p&&p>=dr)
    {
        arb[po].stn=st;
        arb[po].drt=dr;
        arb[po].sumstn=val;
        arb[po].sumdrt=val;
        arb[po].summij=val;
        arb[po].sumtot=val;
        return ;
    }
    arb[po].stn=st;
    arb[po].drt=dr;
    int mij=(st+dr)/2;
    if(p<=mij) update(2*po,st,mij,p,val);
    else update(2*po+1,mij+1,dr,p,val);
    arb[po].sumtot=arb[2*po].sumtot+arb[2*po+1].sumtot;
    arb[po].sumstn=max(arb[2*po].sumstn,arb[2*po].sumtot+arb[2*po+1].sumstn);
    arb[po].sumdrt=max(arb[2*po+1].sumdrt,arb[2*po].sumdrt+arb[2*po+1].sumtot);
    arb[po].summij=max(max(arb[2*po].summij,arb[2*po+1].summij),arb[2*po].sumdrt+arb[2*po+1].sumstn);
}
void interogare(int po, int st, int dr, int a, int b)
{
    if(a<=st&&dr<=b)
    {
        sol=max(sol,max(arb[po].summij,aux+arb[po].sumstn));
        aux=max(aux+arb[po].sumtot, arb[po].sumdrt);
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij) interogare(2*po,st,mij,a,b);
    if(b>mij) interogare(2*po+1,mij+1,dr,a,b);
}
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;i++)
    {
        f>>nr;
        update(1,1,n,i,nr);
    }
    for(int i=1;i<=q;i++)
    {
        f>>x>>y;
        sol=aux=-inf;
        interogare(1,1,n,x,y);
        g<<sol<<'\n';
    }
    return 0;
}
