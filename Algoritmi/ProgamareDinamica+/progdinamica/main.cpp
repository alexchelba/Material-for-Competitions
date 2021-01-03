/// 1. cel mai lung subsir comun
/**
#include <bits/stdc++.h>
using namespace std;
ifstream f("pdin.in");
ofstream g("pdin.out");
vector<int> v1;
int a[1030],b[1030],n,m,k,maxx;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {

    }
    return 0;
}
**/

/// 2. subsir crescator maximal

#include <bits/stdc++.h>
using namespace std;
ifstream f("pdin.in");
ofstream g("pdin.out");
vector<int> v[100001];
int a[100001],n,k,maxx;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
        v[i].push_back(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if(v[i][v[i].size()-1]<a[j]) v[i].push_back(a[j]);
    }
    for(int i=1;i<=n;i++)
    {
        ///g<<v[i].size()<<'\n';
        if(v[i].size()>maxx) {maxx=v[i].size(); k=i;}
    }
    g<<maxx<<'\n';
    for(vector<int>::iterator it=v[k].begin();it!=v[k].end();it++)
        g<<*it<<" ";
    return 0;
}
