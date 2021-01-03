#include <bits/stdc++.h>
using namespace std;
int y,x,r;
int euclid(int a, int b)
{
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void desc(int t)
{
    int d=2;
    int a=t;
    while(d<=t/2)
    {
        int exp=0;
        while(a%d==0)
        {
            a=a/d;
            exp++;
        }
        if(exp) cout<<d<<" "<<exp<<'\n';
        d++;
    }
}
int main()
{
    cin>>x>>y;
    cout<<euclid(x,y)<<'\n';
    desc(x);
    return 0;
}
