#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/**
int viz[101], x, a[101][101], n, m, nr;
queue<int> q;
stack<int> s;
void bfs(){
    do{
        while(q.size()){
            int w = q.front();
            q.pop();
            for(int j=1;j<=n;j++)
                if(a[w][j]!=0)
                    if(viz[j]==0){
                        viz[j]=nr;
                        q.push(j);
                    }
        }
        for(int i=1;i<=n;i++)
            if(!viz[i]) {q.push(i); nr++; viz[i]=nr; break;}
    }while(q.size());
}
void dfs(int k){
    for(int i=1;i<=n;i++)
        if(a[k][i]&&viz[i]==0) {viz[i]=nr; dfs(i);}
    for(int i=1;i<=n;i++)
        if(!viz[i]){nr++; viz[i]=nr; dfs(i);}
}
void afisare_comp_conexe(){
    int k=1;
    while(k<=nr){
        for(int i=1;i<=n;i++)
            if(viz[i]==k) g<<i<<" ";
        g<<'\n';
        k++;
    }
    g<<'\n';
}
void df_ciclu(int k){
    x=s.top();
    ///g<<x<<" ";
    for(int i=1;i<=n;i++)
        if(a[k][i]){
            if(!viz[i]){
                viz[i]=1;
                s.push(i);
                df_ciclu(i);
            }
            else{
                g<<"i "<<x<<" "<<k<<'\n';
                if(x!=k) {a[k][i]=a[i][k]=0; s.pop();}
            }
        }
}
void bf_ciclu(){
    while(q.size()){
        int k = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[k][i]){
                if(!viz[i]){
                    viz[i]=1;
                    q.push(i);
                    a[i][k]=0;
                }
                else{
                    a[i][k]=a[k][i]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j]||a[j][i]) a[i][j]=a[j][i]=1;
    }
}
void afis_matrice(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
    g<<'\n';
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];

    q.push(1); viz[1]=1;
    nr=1;
    bfs();
    afisare_comp_conexe();

    memset(viz,0,sizeof(viz));
    nr=1; viz[1]=1;
    dfs(1);
    afisare_comp_conexe();

    memset(viz,0,sizeof(viz));
    while(q.size()) q.pop();
    viz[1]=1; q.push(1);
    bf_ciclu();
    g<<'\n';
    afis_matrice();

    memset(viz,0,sizeof(viz));
    ///while(q.size()) q.pop();
    viz[1]=1; s.push(1);
    df_ciclu(1);
    g<<'\n';
    afis_matrice();
    return 0;
}
**/

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
