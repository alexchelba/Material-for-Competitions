#include <bits/stdc++.h>
using namespace std;
int nr,n,L,a,x,y,z,t,len ;
int main()
{
    cin>>n>>L>>a;
    if(n>0)
    {
        cin>>x>>y;
        nr=nr+x/a;
        z=x+y;
        for(int i=2;i<=n;i++)
        {
            cin>>t>>len;
            int d=t-z;
            nr=nr+(d/a);
            x=t; z=t+len;
        }
    }
    nr = nr + ((L-z)/a);
    cout<<nr;
    return 0;
}
