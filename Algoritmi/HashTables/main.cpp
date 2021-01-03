#include <bits/stdc++.h>
using namespace std;
ifstream f("hash.in");
ofstream g("hash.out");
int n,m,v[26],i,nr1=0;
const int mod=104729;
long long sum;
char s[2001],*p,cuv[201];
set<char> a[mod];
set<char>::iterator it;
int main()
{
    f.get(s,201);
    p=strtok(s," ,.?!");
    while(p)
    {
        int nr=0,sum=0,m=0;
        for(int i=0;i<strlen(p);i++)
            v[p[i]-'a']++;
        for(int i=0;i<26;i++)
        if(v[i]) {int r=v[i]; while(r) {cuv[m]=(char)(i+'a'); m++; r--;}}
        cuv[m]=NULL;
        ///g<<cuv<<'\n';
        for(int i=0;i<26;i++)
        if(v[i]) {nr++; while(v[i]) {int s1=i*pow(26,nr-1); s1=s1%mod; sum=sum+s1; sum=sum%mod; v[i]--;}}
        it=a[sum].find(*cuv);
        ///g<<sum<<'\n';
        if(a[sum].empty()) nr1++;
        if(it==a[sum].end()) a[sum].insert(*p);
        p=strtok(NULL," ,.?!");
    }
    g<<nr1<<'\n';
    return 0;
}
