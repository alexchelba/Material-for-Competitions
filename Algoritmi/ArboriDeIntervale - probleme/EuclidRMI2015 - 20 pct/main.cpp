#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid1.in");
ofstream g("euclid1.out");
int n,q;
long long arb[300000];
long long cmmdc(long long a, long long b)
{
    ///g<<"r "<<a<<" "<<b<<'\n';
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void update(int po, int st, int dr, int p, long long val)
{
    if(st>=p&&p>=dr) {arb[po]+=abs(val); return ;}
    int mij=(st+dr)/2;
    if(p<=mij) update(2*po,st,mij,p,val);
    else update(2*po+1,mij+1,dr,p,val);
    arb[po]=cmmdc(abs(arb[2*po]),abs(arb[2*po+1]));
    ///else arb[po]=max(arb[2*po],arb[2*po+1]);
}
long long interogare(int po, int st, int dr, int a, int b)
{
    if(st>=a&&b>=dr) return arb[po];
    int mij=(st+dr)/2;
    long long x1=0, x2=0;
    if(a<=mij) x1=interogare(2*po,st,mij,a,b);
    if(b>mij) x2=interogare(2*po+1,mij+1,dr,a,b);
    return cmmdc(x1,x2);
}
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;i++)
    {
        long long x;
        f>>x; x=abs(x);
        update(1,1,n,i,x);
    }
    /**
    int k=1;
    while(arb[k])
    {
        g<<arb[k]<<" ";
        k++;
    }
    g<<'\n';
    **/
    for(int i=1;i<=q;i++)
    {
        int caz;
        f>>caz;
        if(caz==0) {int a,b; f>>a>>b; g<<interogare(1,1,n,a,b)<<'\n';}
        else {long long a,b,k; f>>a>>b>>k; k=abs(k); for(int j=a;j<=b;j++) update(1,1,n,j,(j-a+1)*k);}
    }
    return 0;
}
