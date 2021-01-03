#include <fstream>
using namespace std;
ifstream f("dragoni.in");
ofstream g("dragoni.out");
int a[810][810],n,m,p,viz[810],d[810],x,y,dist,s;
void df(int k)
{
    for(int i=2;i<=n;i++)
    if(a[k][i]&&a[k][i]<=d[1]&&!viz[i]) {viz[i]=1; df(i);}
}
void df1(int k, int distmax)
{
    if(!viz[n])
    {
        for(int i=1;i<=n;i++)
        if(a[k][i]&&a[k][i]<=distmax&&!viz[i]) {viz[i]=1; if(d[i]>distmax) distmax=d[i]; s+=a[k][i]; df1(i,distmax);}
    }
}
int main()
{
    f>>p;
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>d[i];
    }
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>dist;
        a[x][y]=dist;
        a[y][x]=dist;
    }
    if(p==1)
    {
        df(1);
        int maxx=0;
        for(int i=1;i<=n;i++)
            if(viz[i]) if(d[i]>maxx) maxx=d[i];
        g<<maxx<<'\n';
    }
    else
    {
        viz[1]=1;
        df1(1,d[1]);
        g<<s<<'\n';
    }
    return 0;
}
