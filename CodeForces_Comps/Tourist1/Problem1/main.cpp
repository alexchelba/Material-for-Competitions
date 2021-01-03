#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,x;
int main()
{
    cin>>n;
    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2==1)
        {
            if(!ok) {x--; ok^=1;}
            else {x++; ok^=1;}
        }
        cout<<x/2<<'\n';
    }
    return 0;
}
