#include <bits/stdc++.h>
using namespace std;
ifstream f("biperm.in");
ofstream g("biperm.out");
/**
int n,v1[10001],v2[10001],viz1[10001],viz2[10001];
vector<pair<int, int> > v[10001];
queue<int> c;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>v1[i]; viz1[v1[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        f>>v2[i]; viz2[v2[i]]++;
        v[v2[i]].push_back(make_pair(v1[i],i));
    }
    int nr=0;
    for(int k=1;k<=n;k++)
    {
        if(viz2[v2[k]]==2)
        {
            int i=v2[k];
            c.push(i);
            while(!c.empty())
            {
                nr++;
                int w=c.front();
                c.pop();
                for(int j=0;j<v[i].size();j++)
                if(v[i][j].first!=i&&viz2[v[i][j].first]==0)
                {
                    viz2[v[i][j].first]++;
                    viz1[v[i][j].first]--;
                    viz2[i]--;
                    c.push(v[i][j].first);
                    swap(v2[v[i][j].second],v1[v[i][j].second]);
                }
            }
        }
    }
    g<<"0"<<" "<<nr<<'\n';
    for(int i=1;i<=n;i++)
        g<<v1[i]<<" ";
    g<<'\n';
    for(int i=1;i<=n;i++)
        g<<v2[i]<<" ";
    return 0;
}
**/
int n,a[410][410],b[410][410],nr1,nr,viz[410],v1[410],v2[410],viz1[10001],viz2[10001];
vector<int> vi1[410];
vector<pair<int, int> > v[10001];
queue<int> c;
void ciclu(int k, int m)
{
    ///g<<k<<" ";
    for(int i=1;i<=n;i++)
    if(a[k][i]&&!viz[i])
    {
        viz[i]=1;
        vi1[m].push_back(i);
        ciclu(i,m);
    }
    else if(i==m&&a[k][m]==1) {nr1++; vi1[m].push_back(i); return ;}
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>v1[i]; viz1[v1[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        f>>v2[i]; viz2[v2[i]]++;
        v[v2[i]].push_back(make_pair(v1[i],i));
    }
    for(int i=1;i<=n;i++)
    {
        if(a[v1[i]][v2[i]]==0) a[v1[i]][v2[i]]=1;
        else {a[v2[i]][v1[i]]=1; nr++;}
    }
    for(int i=1;i<=n;i++)
    {
        vi1[i].push_back(i);
        viz[i]=1;
        ciclu(i,i);
    }
    g<<(1<<(nr1))<<" "<<nr<<'\n';
    int nr=0;
    for(int k=1;k<=n;k++)
    {
        if(viz2[v2[k]]==2)
        {
            int i=v2[k];
            c.push(i);
            while(!c.empty())
            {
                nr++;
                int w=c.front();
                c.pop();
                for(int j=0;j<v[i].size();j++)
                if(v[i][j].first!=i&&viz2[v[i][j].first]==0)
                {
                    viz2[v[i][j].first]++;
                    viz1[v[i][j].first]--;
                    viz2[i]--;
                    c.push(v[i][j].first);
                    swap(v2[v[i][j].second],v1[v[i][j].second]);
                }
            }
        }
    }
    ///g<<"0"<<" "<<nr<<'\n';
    for(int i=1;i<=n;i++)
        g<<v1[i]<<" ";
    g<<'\n';
    for(int i=1;i<=n;i++)
        g<<v2[i]<<" ";
    return 0;
}
