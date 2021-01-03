#include <bits/stdc++.h>
using namespace std;
ifstream f("spion.in");
ofstream g("spion.out");
int p,k,y;
int prim=100003;
char s[100001];
long long fact(int k)
{
    long long p=1;
    for(int i=2;i<=k;i++)
    {
        p=p*i;
        p=p%prim;
    }
    return p;
}
long long inv_mod(long long a, long long b)
{
    long long x=0,y=0,z=1,r=0,c=0,initial;
    initial=b;
    while(a)
    {
        r=b%a;
        c=b/a;
        b=a;
        a=r;
        x=y-c*z;
        y=z;
        z=x;
    }
    while(y<0) y+=initial;
    return y;
}
int main()
{
    f>>p;
    f.get();
    f.get(s,100001);
    int d=0;
    for(int i=0;i<strlen(s);i++)
    if(s[i]=='E') d++;
    if(p==1) g<<d+1;
    else
    {
        int n=strlen(s);
        ///g<<n<<" "<<d<<'\n';
        ///g<<fact(n)<<'\n';
        ///g<<inv_mod(fact(d),prim)<<'\n';
        ///g<<inv_mod(2,prim)<<'\n';
        long long p1=fact(n)*inv_mod(fact(d)*fact(n-d),prim);
        g<<p1%100003<<'\n';
    }return 0;}
