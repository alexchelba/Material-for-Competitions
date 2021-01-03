#include <fstream>
using namespace std;
ifstream f("suma4.in");
ofstream g("suma4.out");
int n,i,niv,a[60][60][60],b[60][60][60];
int main()
{
    f>>n;
    int ok=1, s1=0, s2=0;
    for(int i=1;i<=n&&ok;i++)
    {
        s1=i*(i-1)*(2*i-1)/6;
        s2=i*(i+1)*(2*i+1)/6;
        if(s1<n&&n<=s2) {g<<i<<" "; niv=i; ok=0;}
    }
    for(int k=1;k<=niv;k++)
    {
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
            {f>>a[i][j][k]; b[i][j][k]=a[i][j][k];}
    }
    for(int k=1;k<niv;k++)
    {
        for(int i=1;i<=k+1;i++)
        for(int j=1;j<=k+1;j++)
        {
            int nr=0;
            if(b[i][j][k+1]==a[i][j][k+1])
            {
                if(b[i][j][k]) {b[i][j][k+1]+=b[i][j][k]; nr=1;}
                else
                if(b[i-1][j][k]) {b[i][j][k+1]+=b[i-1][j][k]; nr=2;}
                else
                if(b[i][j-1][k]) {b[i][j][k+1]+=b[i][j-1][k]; nr=3;}
                else
                if(b[i-1][j-1][k]) {b[i][j][k+1]+=b[i-1][j-1][k]; nr=4;}
            }
            if(nr==1)
            {
                if(b[i-1][j][k]&&b[i-1][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j][k]+a[i][j][k+1];
                if(b[i][j-1][k]&&b[i][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i][j-1][k]+a[i][j][k+1];
                if(b[i-1][j-1][k]&&b[i-1][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j-1][k]+a[i][j][k+1];
            }
            else
            if(nr==2)
            {
                if(b[i][j][k]&&b[i][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=a[i][j][k]+a[i][j][k+1];
                if(b[i][j-1][k]&&b[i][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=a[i][j-1][k]+a[i][j][k+1];
                if(b[i-1][j-1][k]&&b[i-1][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j-1][k]+a[i][j][k+1];
            }
            else
            if(nr==3)
            {
                if(b[i][j][k]&&b[i][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i][j][k]+a[i][j][k+1];
                if(b[i-1][j][k]&&b[i-1][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j][k]+a[i][j][k+1];
                if(b[i-1][j-1][k]&&b[i-1][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j-1][k]+a[i][j][k+1];
            }
            else
            if(nr==4)
            {
                if(b[i][j][k]&&b[i][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i][j][k]+a[i][j][k+1];
                if(b[i-1][j][k]&&b[i-1][j][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i-1][j][k]+a[i][j][k+1];
                if(b[i][j-1][k]&&b[i][j-1][k]+a[i][j][k+1]<b[i][j][k+1]) b[i][j][k+1]=b[i][j-1][k]+a[i][j][k+1];
            }
        }
    }
    /**for(int k=1;k<=niv;k++)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
                g<<b[i][j][k]<<" ";
            g<<'\n';
        }
        g<<'\n';
    }**/
    int minn=2000000000;
    for(int i=1;i<=niv;i++)
    {
        for(int j=1;j<=niv;j++)
            if(b[i][j][niv]<minn) minn=b[i][j][niv];
    }
    g<<minn;
    return 0;
}
