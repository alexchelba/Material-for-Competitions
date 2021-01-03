/// 100 pct
#include <bits/stdc++.h>
using namespace std;
ifstream f("heavypath.in");
ofstream g("heavypath.out");
int n,q,sol,nrlant,nrfii[100001],niv[100001],val[100001],wh[100001],pozi[100001],tata[100001];
vector<int> v[100001],lant[100001],arb[100001];
void df(int k, int tati)
{
    int poz=0;
    nrfii[k]=1;
    for(auto it:v[k])
    if(it!=tati)
    {
        niv[it]=niv[k]+1;
        df(it,k);
        nrfii[k]+=nrfii[it];
        if(nrfii[it]>nrfii[poz]) poz=it;
    }
    if(!poz)
    {
        lant[++nrlant].push_back(k);
        wh[k]=nrlant;
        pozi[k]=1;
    }
    else
    {
        wh[k]=wh[poz];
        lant[wh[k]].push_back(k);
        pozi[k]=lant[wh[k]].size();
    }
    for(auto it: v[k])
        if(it!=tati&&it!=poz)
        tata[wh[it]]=k;
}
void update(int ind, int po, int st, int dr, int x, int val)
{
    if(st==dr)
    {
        arb[ind][po]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(x<=mij) update(ind,2*po,st,mij,x,val);
    else update(ind,2*po+1,mij+1,dr,x,val);
    arb[ind][po]=max(arb[ind][2*po],arb[ind][2*po+1]);
}
int interogheaza(int ind, int po, int st, int dr, int x, int y)
{
    if(x<=st&&dr<=y) return arb[ind][po];
    int mij=(st+dr)/2, x1=0,x2=0;
    if(x<=mij) x1=interogheaza(ind,2*po,st,mij,x,y);
    if(y>mij) x2=interogheaza(ind, 2*po+1,mij+1,dr,x,y);
    return max(x1,x2);
}
void precompute()
{
    for(int i=1;i<=nrlant;i++)
        arb[i].resize(lant[i].size()*4+5);
    for(int i=1;i<=nrlant;i++)
        for(int j=0;j<lant[i].size();j++)
        update(i,1,1,lant[i].size(),j+1,val[lant[i][j]]);
}
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;i++)
        f>>val[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    niv[1]=1;
    df(1,0);
    precompute();
    for(int i=1;i<=q;i++)
    {
        int caz,x,y;
        f>>caz>>x>>y;
        if(caz==0) update(wh[x],1,1,lant[wh[x]].size(),pozi[x],y);
        else
        {
            sol=0;
            while(wh[x]!=wh[y])
            {
                if(niv[tata[wh[x]]]<niv[tata[wh[y]]])
                    swap(x,y);
                sol=max(sol,interogheaza(wh[x],1,1,lant[wh[x]].size(),pozi[x],lant[wh[x]].size()));
                x=tata[wh[x]];
            }
            sol=max(sol,interogheaza(wh[x],1,1,lant[wh[x]].size(),min(pozi[x],pozi[y]),max(pozi[x],pozi[y])));
            g<<sol<<'\n';
        }
    }
    return 0;
}
