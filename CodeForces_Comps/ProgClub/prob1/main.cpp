#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[55];
int main()
{
    int nr=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        a[0]=0;
        for(int i=0;i<s.length();i++)
            a[++a[0]]=s[i]-'0';
        int j=1;
        while(a[j]==a[a[0]-j+1]&&j<a[0]-j+1) j++;
        if(j>=a[0]-j+1) nr++;
    }
    cout<<nr<<'\n';
    return 0;
}
