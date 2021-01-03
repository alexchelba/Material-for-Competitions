/// 100 pct
#include<bits/stdc++.h>
using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
long long a,b;
///int x=0, y=0, z=1, r=0, c=0;
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
    f>>a>>b;
    g<<inv_mod(a,b);
    return 0;
}
