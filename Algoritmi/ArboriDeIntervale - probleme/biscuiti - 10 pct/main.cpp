#include <bits/stdc++.h>
#define inf 2000000000000000000
using namespace std;
ifstream f("biscuiti.in");
ofstream g("biscuiti.out");
int n,x;
long long s1,s2,arb[300000],lazy[300000];
vector<int> v;
void update(int po, int st, int dr, int p, int val)
{
    if(st>=p&&p>=dr) {arb[po]=val; return ;}
    int mij=(st+dr)/2;
    if(p<=mij) update(2*po,st,mij,p,val);
    else update(2*po+1,mij+1,dr,p,val);
    if(arb[2*po]<arb[2*po+1]&&arb[2*po]) arb[po]=arb[2*po];
    else arb[po]=arb[2*po+1];
}
void updaterange(int po, int st, int dr, int a, int b, int val)
{
    if(lazy[po])
    {
        arb[po]+=(dr-st+1)*lazy[po];
        if(st!=dr)
        {
            lazy[2*po]+=lazy[po];
            lazy[2*po+1]+=lazy[po];
        }
        lazy[po]=0;
    }
    if(st>dr||st>b||dr<a) return;
    if(a<=st&&dr<=b)
    {
        arb[po]+=(dr-st+1)*val;
        if(st!=dr)
        {
            lazy[2*po]+=val;
            lazy[2*po+1]+=val;
        }
        return;
    }
    int mij=(st+dr)/2;
    updaterange(2*po,st,mij,a,b,val);
    updaterange(2*po+1,mij+1,dr,a,b,val);
    arb[po]=min(arb[2*po],arb[2*po+1]);
}
int interogrange(int po, int st, int dr, int a, int b)
{
    g<<st<<" "<<dr<<" "<<a<<" "<<b<<'\n';
    ///if(st>dr||st>b||dr<a) return 0;
    if(lazy[po])
    {
        arb[po]+=(dr-st+1)*lazy[po];
        if(st!=dr)
        {
            lazy[2*po]+=lazy[po];
            lazy[2*po+1]+=lazy[po];
        }
        lazy[po]=0;
    }
    if(a<=st&&dr<=b) return arb[po];
    int mij=(st+dr)/2, p1=0, p2=0;
    if(a<=mij) p1=interogrange(2*po,st,mij,a,b);
    if(b>mij) p2=interogrange(2*po+1,mij+1,dr,a,b);
    return min(p1,p2);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        v.push_back(x);
        s1+=x;
        update(1,1,n,i,x);
    }
    int t=0, m=n;
    while(m)
    {
        t++; m--;
        int poz=n+1, minn=inf;
        for(int i=0;i<v.size();i++)
            if(v[i]<minn&&v[i]>=1) minn=v[i],poz=i;
        if(poz!=n+1)
        {
            s2+=v[poz];
            v[poz]=-1;
            poz++;
            g<<interogrange(1,1,n,poz,poz)<<'\n';
            updaterange(1,1,n,1,poz,t);
        }
    }
    g<<s2-s1<<'\n';
    return 0;
}
