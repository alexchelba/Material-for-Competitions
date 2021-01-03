#include <bits/stdc++.h>
#define inf 100001
using namespace std;
ifstream f("coach.in");
ofstream g("coach.out");
struct data{
    int nod, cost, minn, maxx;
};
int t,n,m,a[101][101],b[101][101],cal[101],mincal,maxcal,p,viz[101];
queue<data> q;
void bfs(){
    if(!q.size()) return;
    data x;
    x=q.front();
    q.pop();
    for(int i=1;i<=n;i++){
        data y;
        if(b[x.nod][i]&&!viz[i]){
            viz[i]=1;
            y.nod=i;
            y.cost=x.cost+b[x.nod][i];
            y.minn=min(x.minn,cal[i]);
            y.maxx=max(x.maxx,cal[i]);
            q.push(y);
            ///g<<y.nod<<" "<<y.cost<<" "<<y.minn<<" "<<y.maxx<<'\n';
            if(y.nod==p&&y.cost==t) {mincal=y.minn; maxcal=y.maxx; return;}
            bfs();
            viz[i]=0;
        }
    }
}
void descompun_drum(int i,int j)
{
    int ok=0,k=1;
    while(k<=n&&!ok)
    {
    if(i!=k&&j!=k)
    if(a[i][j]==a[i][k]+a[k][j])
    {
        descompun_drum(i,k);
        descompun_drum(k,j);
        ok=1;
    }
    k++;
    }
    if(!ok)
    {
        //g<<j<<" ";
        if(cal[j]<mincal) mincal=cal[j];
        if(cal[j]>maxcal) maxcal=cal[j];
    }
}

void scriu_drum(int nod_initial,int nod_final)
{
    if(a[nod_initial][nod_final]<inf)
    {
        //g<<nod_initial<<" ";
        mincal=maxcal=cal[nod_initial];
        descompun_drum(nod_initial,nod_final);
    }
}
int main()
{
    f>>n>>m>>t;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        a[i][j]=inf;
        if(i==j) a[i][j]=0;
    }
    for(int i=1;i<=n;i++)
        f>>cal[i];
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        f>>x>>y>>c;
        b[x][y]=a[x][y]=c;
        b[y][x]=a[y][x]=c;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
    /**
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
    **/
    int maxx=0, pi=0, pf=0,pim=0,pfm=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(a[i][j]==t) {pi=min(i,j); pf=max(i,j); break;}
        else
        if(a[i][j]>maxx) maxx=a[i][j],pim=min(i,j),pfm=max(i,j);
    if(pi&&pf)
    {
        g<<pi<<" "<<pf<<" ";
        scriu_drum(pi,pf);
        g<<mincal<<" "<<maxcal<<'\n';
    }
    else{
        p=pfm;
        data x;
        x.nod=pim;
        x.cost=0;
        x.minn=cal[pim];
        x.maxx=cal[pim];
        q.push(x);
        viz[pim]=1;
        bfs();
        g<<pim<<" "<<pfm<<" "<<mincal<<" "<<maxcal<<'\n';
    }
    return 0;
}
