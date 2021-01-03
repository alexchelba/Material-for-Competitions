#include <bits/stdc++.h>
using namespace std;
ifstream f("blis.in");
ofstream g("blis.out");
int k,x,nr;
/**
char s[100005];
deque<int> c;
int calcul()
{
    int s=0;
    for(int i=0;i<c.size();i++)
        s=s+(c[i]<<(k-i-1));
    return s;
}
int main()
{
    f>>k;
    f.get();
    f.get(s,100005);
    int maxx=0, i=0;
    while(i<strlen(s))
    {
        nr++;
        x=s[i]-'0';
        c.push_back(x);
        if(nr==k) {if(calcul()>maxx) maxx=calcul();}
        if(nr>k) {c.pop_front(); if(calcul()>maxx) maxx=calcul();}
        i++;
    }
    if(nr<=k) maxx=calcul();
    g<<maxx<<'\n';
    return 0;
}
**/

int bit;
int main()
{
    f>>k;
    char c;
    for(int i=k;i>=1;i--)
    {
        f>>c;
        bit=c-'0';
        nr=nr|(bit<<i-1);
    }
    int maxx=nr;
    ///g<<nr<<'\n';
    while(f>>c)
    {
        bit=c-'0';
        if(nr&(1<<(k-1)))
        nr=nr&~(1<<(k-1));
        ///g<<nr<<'\n';
        int m=(nr<<1)+bit;
        nr=m;
        if(nr>maxx) maxx=nr;
        ///g<<nr<<'\n';
        ///g<<'\n';
    }
    g<<maxx<<'\n';
    return 0;
}
