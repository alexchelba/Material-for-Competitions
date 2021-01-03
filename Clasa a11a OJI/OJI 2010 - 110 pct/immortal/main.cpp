#include <fstream>
using namespace std;
ifstream f("immortal.in");
ofstream g("immortal.out");
struct imm
{
    int lin,col;
};
imm a[410],t[410];
/**
int n,m,p,b[25][25],c[25][25],viz[25][25];
int egal()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(viz[i][j]!=b[i][j]) return 0;
    return 1;
}
void backt(int &pr, int i, int j, int &nr)
{
    if(egal())
    {
        for(int j=1;j<nr;j++)
            g<<t[j].lin<<" "<<t[j].col<<" "<<t[j+1].lin<<" "<<t[j+1].col<<'\n';
        pr=p+1;
        return ;
    }
    if(i<=n&&j<=m)
    {
        if(b[i+1][j]==1&&!viz[i+1][j]&&b[i+2][j]==0&&i<=n-1) {viz[i+1][j]=1; nr++; t[nr].lin=i+2; t[nr].col=j; backt(pr,i+2,j,nr); viz[i+1][j]=0; nr--;}
        if(b[i-1][j]==1&&!viz[i-1][j]&&b[i-2][j]==0&&i>1) {viz[i-1][j]=1; nr++; t[nr].lin=i-2; t[nr].col=j; backt(pr,i-2,j,nr); viz[i-1][j]=0; nr--;}
        if(b[i][j+1]==1&&!viz[i][j+1]&&b[i][j+2]==0&&j<=m-1) {viz[i][j+1]=1; nr++; t[nr].lin=i; t[nr].col=j+2; backt(pr,i,j+2,nr); viz[i][j+1]=0; nr--;}
        if(b[i][j-1]==1&&!viz[i][j-1]&&b[i][j-2]==0&&j>1) {viz[i][j-1]=1; nr++; t[nr].lin=i; t[nr].col=j-2; backt(pr,i,j-2,nr); viz[i][j-1]=0; nr--;}
    }
}
void afis(int v[25][25])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            g<<v[i][j]<<" ";
        g<<'\n';
    }
}
int main()
{
    f>>n>>m>>p;
    for(int i=1;i<=p;i++)
    {
        int x,y;
        f>>x>>y;
        a[i].lin=x;
        a[i].col=y;
        b[x][y]=1; ///c[x][y]=1;
    }
    for(int i=0;i<=n+1;i++)
    {
        b[i][0]=-1;
        b[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;i++)
    {
        b[0][i]=-1;
        b[n+1][i]=-1;
    }
    for(int i=1;i<=p;i++)
    {
        int nr=1;
        t[nr].lin=a[i].lin;
        t[nr].col=a[i].col;
        viz[a[i].lin][a[i].col]=1;
        int pr=i;
        backt(pr,a[i].lin, a[i].col,nr);
        if(pr==p+1) {i=p+1; break;}
        viz[a[i].lin][a[i].col]=0;
    }
    return 0;
}
**/

int n,m,p,kkk=0,b[25][25],c[25][25],viz[25][25];
int egal()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(viz[i][j]!=b[i][j]) return 0;
    return 1;
}
void backt(int &pr, int i, int j, int &nr)
{
    if(kkk) return ;
    if(egal())
    {
        kkk=1;
        for(int j=1;j<nr;j++)
            g<<t[j].lin<<" "<<t[j].col<<" "<<t[j+1].lin<<" "<<t[j+1].col<<'\n';
        pr=p+1;
        return ;
    }
    if(i<=n&&j<=m)
    {
        if(b[i+1][j]==1&&!viz[i+1][j]&&b[i+2][j]==0&&i<=n-1) {viz[i+1][j]=1; nr++; t[nr].lin=i+2; t[nr].col=j; backt(pr,i+2,j,nr); viz[i+1][j]=0; nr--;}
        if(b[i-1][j]==1&&!viz[i-1][j]&&b[i-2][j]==0&&i>1) {viz[i-1][j]=1; nr++; t[nr].lin=i-2; t[nr].col=j; backt(pr,i-2,j,nr); viz[i-1][j]=0; nr--;}
        if(b[i][j+1]==1&&!viz[i][j+1]&&b[i][j+2]==0&&j<=m-1) {viz[i][j+1]=1; nr++; t[nr].lin=i; t[nr].col=j+2; backt(pr,i,j+2,nr); viz[i][j+1]=0; nr--;}
        if(b[i][j-1]==1&&!viz[i][j-1]&&b[i][j-2]==0&&j>1) {viz[i][j-1]=1; nr++; t[nr].lin=i; t[nr].col=j-2; backt(pr,i,j-2,nr); viz[i][j-1]=0; nr--;}
    }
}
void afis(int v[25][25])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            g<<v[i][j]<<" ";
        g<<'\n';
    }
}
int main()
{
    f>>n>>m>>p;
    for(int i=1;i<=p;i++)
    {
        int x,y;
        f>>x>>y;
        a[i].lin=x;
        a[i].col=y;
        b[x][y]=1; ///c[x][y]=1;
    }
    for(int i=0;i<=n+1;i++)
    {
        b[i][0]=-1;
        b[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;i++)
    {
        b[0][i]=-1;
        b[n+1][i]=-1;
    }
    for(int i=1;i<=p;i++)
    {
        int nr=1;
        t[nr].lin=a[i].lin;
        t[nr].col=a[i].col;
        ///viz[a[i].lin][a[i].col]=0;
        b[a[i].lin][a[i].col]=0;
        int pr=i;
        backt(pr,a[i].lin, a[i].col,nr);
        if(pr==p+1) {i=p+1; break;}
        ///viz[a[i].lin][a[i].col]=0;
        b[a[i].lin][a[i].col]=1;
    }
    return 0;
}
