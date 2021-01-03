#include <fstream>
#include<iomanip>
using namespace std;
ifstream f("cartite.in");
ofstream g("cartite.out");
struct coada
{
    int x,y,nr;
};
coada c[45000];
int p,n,m,nrg,xv,yv,nrv,x,y,dist,a[210][210],pozi,pozj;
int dl[]={-1,0,1,0}, dc[]={0,-1,0,1};
int v[1000],b[210][210],nr,gr[210];
void drumpanalagalerii()
{
    int st=1, sf=1;
    c[1].x=xv; c[1].y=yv;
    while(st<=sf)
    {
        coada w=c[st];
        for(int i=0;i<4;i++)
        {
            if(a[w.x+dl[i]][w.y+dc[i]]==0)
            {
                a[w.x+dl[i]][w.y+dc[i]]=1;
                sf++; c[sf].nr=w.nr+1;
                c[sf].x=w.x+dl[i];
                c[sf].y=w.y+dc[i];
            }

            if(a[w.x+dl[i]][w.y+dc[i]]==2)
            {
                if(p==1)
                g<<w.x+dl[i]<<" "<<w.y+dc[i]<<" "<<w.nr+1<<'\n';
                else
                {
                    pozi=w.x+dl[i];
                    pozj=w.y+dc[i];
                }
            }
        }
        st++;
    }
}
int grad(int k)
{   int s=0;            /// in s este calculate gradul, asa ca se initializeaza cu 0
    for(int i=1;i<=n;i++)
        if(b[k][i]==1)      /// atunci cand este gasit un nod cu care nodul k este legat
            s++;     /// prin muchie, gradul nodului k creste
    return s;        /// functia returneaza gradul nodului k
}
void ciclu_eulerian(int k)
{
    int maxx=0, nmax=0;
    g<<(v[k]>>8)<<" "<<v[k]%256<<'\n';    ///afis vf curent
    for(int i=1;i<=n;i++)     /// cauta varful urmator cu grad maxim
    {   if(b[k][i]==1)
            if(gr[i]>maxx)
                maxx=grad(i),nmax=i;
    }
    if(nmax!=0)
    {   b[k][nmax]=b[nmax][k]=0;      ///sterge muchia
        gr[k]--;             ///scade gradele celor 2 noduri incidente cu muchia stearsa
        gr[nmax]--;
        ciclu_eulerian(nmax);        ///apel recursiv la varful urmator
    }
}
int main()
{
    f>>p;
    f>>n>>m;
    f>>xv>>yv;
    a[xv][yv]=1;
    f>>nrv;
    for(int i=1;i<=nrv;i++)
    {
        f>>x>>y>>dist;
        a[x][y]=-1;
        if(dist==1)
        {
            a[x-1][y]=-1;
            a[x+1][y]=-1;
            a[x][y-1]=-1;
            a[x][y+1]=-1;
        }
        else
        if(dist==2)
        {
            a[x-1][y]=-1;
            a[x-2][y]=-1;
            a[x+1][y]=-1;
            a[x+2][y]=-1;
            a[x][y-1]=-1;
            a[x][y-2]=-1;
            a[x][y+1]=-1;
            a[x][y+2]=-1;
            a[x-1][y-1]=-1;
            a[x-1][y+1]=-1;
            a[x+1][y-1]=-1;
            a[x+1][y+1]=-1;
        }
    }
    f>>nrg;
    for(int i=1;i<=nrg;i++)
    {
        int stl,stc,sfl,sfc;
        f>>stl>>stc>>sfl>>sfc;
        if(a[stl][stc]!=-1) a[stl][stc]=2;
        if(a[sfl][sfc]!=-1) a[sfl][sfc]=2;
        int nr1, nr2;
        nr1=(stl<<8)|stc;
        nr2=(sfl<<8)|sfc;
        int ok=1,ok2=1,poz1=0,poz2=0;
        for(int j=1;j<=nr&&ok;j++)
            if(v[j]==nr1) {ok=0; poz1=j;}
        for(int j=1;j<=nr&&ok2;j++)
            if(v[j]==nr2) {ok2=0; poz2=j;}
        if(ok) {nr++; v[nr]=nr1; poz1=nr;}
        if(ok2) {nr++; v[nr]=nr2; poz2=nr;}
        ///g<<poz1<<" "<<poz2<<'\n';
        b[poz1][poz2]=1;
        b[poz2][poz1]=1;
    }
    for(int i=0;i<=n+1;i++)
    {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }
    for(int j=0;j<=m+1;j++)
    {
        a[0][j]=-1;
        a[n+1][j]=-1;
    }
/**
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }
**/
    drumpanalagalerii();
/**
    g<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }
**/
    if(p==2)
    {
        /**
        int k;
        for(int i=1;i<=nr;i++)
        if(((pozi<<8)|pozj)==v[i]) {k=i; break;}
        **/
        for(int i=1;i<=n;i++)
            gr[i]=grad(i);
        ciclu_eulerian(1);
    }
    return 0;
}
