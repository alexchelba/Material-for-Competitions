#include <bits/stdc++.h>
using namespace std;
ifstream f("urat.in");
ofstream g("urat.out");
long long n,maxx,nr;
vector<int> sol;
deque<int> s;
long long fact(int k)
{
    long long p=1;
    for(int i=2;i<=k;i++)
        {p=p*i; p=p%543217;}
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
long long comb(int n, int k)
{
    long long x=fact(n),y=fact(k),z=fact(n-k);
    long long c=inv_mod(y*z,543217);
    return (x*c)%543217;
}
int main()
{
    f>>n;
    s.push_back(n/2);
    for(int i=1;i<n/2;i++)
        s.push_back(i);
    s.push_back(n/2+1);
    for(int i=n;i>n/2+1;i--)
        s.push_back(i);
    while(s.size())
    {
        sol.push_back(s.front());
        s.pop_front();
        if(s.size())
        {
            nr++;
            sol.push_back(s.back()); s.pop_back();
        }
    }
    for(int i=0;i<sol.size()-1;i++)
        maxx=maxx+abs(sol[i+1]-sol[i]);
    nr=nr+n-2*nr;
    g<<maxx<<'\n';
    if(n%2==0) g<<(2*fact(n/2-1)*fact(n/2-1))%543217<<'\n';
    else g<<(4*fact((n-1)/2)*fact((n-1)/2-1))%543217<<'\n';
    for(int i=0;i<n;i++)
        g<<sol[i]<<" ";
    g<<'\n';
    return 0;
}
