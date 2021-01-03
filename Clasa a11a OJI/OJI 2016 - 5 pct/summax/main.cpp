#include <fstream>
using namespace std;
ifstream f("summax.in");
ofstream g("summax.out");
int p,n,st,ok,dr,a[2001][2001],s,maxx,nr,b[2001];
int main()
{
    f>>p;
    f>>n>>st>>dr;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        f>>a[i][j];
    if(p==1)
    {
        do
        {
            ok=1;
            s=a[1][1];
            int j=1;
            for(int i=2;i<=n;i++)
                {
                    j=j+b[i-1];
                    s=s+a[i][j];
                }
            if(s>maxx) {maxx=s; nr=1;}
            else if(s==maxx) nr++;
            if(nr>2000000000) nr=2000000001;
            ///for(int i=1;i<=n-1;i++) g<<b[i]<<" ";
            ///g<<'\n'<<s<<'\n';
            for(int i=1;i<=n-1&&ok;i++)
                if(!b[i]) ok=0;
            int i=n-1;
            while(b[i]&&i>=1) {b[i]=0; i--;}
                if(i>=1) b[i]=1;
        }while(!ok);
        g<<nr<<'\n';
    }
    return 0;
}
