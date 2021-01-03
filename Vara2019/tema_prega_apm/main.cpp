#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define nmax 200005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/** /// apm pe matrici
int a[101][101],nod,n,m,s[101],t[101],cost;
int cauta_nod(int &k){
    int minn=inf;
    for(int i=1;i<=n;i++)
        if(s[i])
            if(a[i][s[i]]<minn) {
                minn=a[i][s[i]];
                k=i;
            }
    return minn;
}
void actualizeaza(int k){
    for(int i=1;i<=n;i++)
        if(s[i]&&a[i][k]<a[i][s[i]]){
            s[i]=k;
        }
}
int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=inf;
            if(i==j) a[i][j]=0;
        }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        a[x][y]=a[y][x]=z;
    }
    memset(t,0,sizeof(t));
    memset(s,1,sizeof(s));
    nod=1; s[nod]=0;
    for(int i=1;i<=n-1;i++){
        int min1=cauta_nod(nod);
        t[nod]=s[nod];
        s[nod]=0;
        cost+=min1;
        actualizeaza(nod);
    }
    g<<cost<<'\n';
    for(int i=1;i<=n;i++)
        g<<t[i]<<" ";
    return 0;
}
**/

/** /// apm Kruskal
int n,m,i,j,t[1001],x,y,c,cost,a,b;
pair<int, pair<int, int> > M[2000];
vector<pair<int, int> > sol;
int compr(int v)
{
    if(t[v]==v)
        return v;
    t[v]=compr(t[v]);
    return t[v];
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        M[i]={c,{x,y}};
    }
    sort(M+1,M+m+1);
    for(i=1;i<=n;i++)
        t[i]=i;
    i=1;
    j=n-1;
    while(j)
    {
        a=M[i].second.first;
        b=M[i].second.second;
        x=compr(a);
        y=compr(b);
        if(x!=y)
        {
            t[x]=y;
            cost+=M[i].first;
            sol.push_back({a,b});
            j--;
        }
        i++;
    }
    g<<cost<<'\n'<<n-1<<'\n';
    for(vector<pair<int,int> >:: iterator it=sol.begin();it!=sol.end();it++)
    {
        g<<it->first<<" "<<it->second<<'\n';
    }
    return 0;
}
**/

/** /// Desen
int n,i,j,t[1005],x[1005],y[1005],a,b,p,q;
double c, cost;
vector<pair<double, pair<int, int> > > mo;
vector<pair<double, pair<int, int> > > sol;
int compr(int v)
{
    if(t[v]==v)
        return v;
    t[v]=compr(t[v]);
    return t[v];
}
int main()
{
    f>>n;
    for(int k=1;k<=n;k++)
    {
        f>>x[k]>>y[k];
        for(int j=k-1;j>=1;j--){
            c = sqrt((x[k]-x[j])*(x[k]-x[j]) + (y[k]-y[j])*(y[k]-y[j]));
            mo.push_back({c,{k,j}});
        }
    cost=0;
    sort(mo.begin(),mo.end());
    for(i=1;i<=k;i++)
        t[i]=i;
    i=0;
    j=k-1;
    while(j)
    {
        a=mo[i].second.first;
        b=mo[i].second.second;
        p=compr(a);
        q=compr(b);
        if(p!=q)
        {
            t[p]=q;
            cost+=mo[i].first;
            sol.push_back({mo[i].first,{a,b}});
            j--;
        }
        i++;
    }
    g<<fixed;
    g<<setprecision(6)<<cost<<'\n';
    mo=sol;
    sol.clear();
    }
    return 0;
}
**/
