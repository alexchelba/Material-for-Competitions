#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/// apm pe matrici
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
