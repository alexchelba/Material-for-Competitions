#include <bits/stdc++.h>
using namespace std;
int a,b,n;
int main()
{
    cin>>a>>n;
    if(n%a==0) cout<<a<<'\n';
    else{
        int p=1;
        while(a*p<n) p++;
        p--;
        while(a*p<n) a++;
        cout<<a<<'\n';
    }
    return 0;
}
