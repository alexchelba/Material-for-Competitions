#include <fstream>
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
int a[2001][4001];
int t,n,k;
long long s;
long long suma(int n)
{
    if(n==1) return 3;
    else
    {
        if(n%2==1) return 3*suma(n-1)%100003;
        else return suma(n/2)*suma(n/2)%100003;
    }
}
void mancare(int j, int k)
{
    if(j<=n+1&&k<=2*n+1)
    {
        s=s+a[j][k];
        s=s%100003;
        mancare(j+1,k+2);
    }
}
int main()
{
    f>>t;
    f>>n>>k;

    if(t==1)
    {
        s=suma(k-1);
        g<<s%100003<<'\n';
    }
    else
    {
        for(int i=1;i<=n+1;i++)
        {
            a[i][n+2-i]=1;
            a[i][n+i]=1;
        }
        for(int i=2;i<=n+1;i++)
            for(int j=n+2-i;j<=n+i-1;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j]+a[i-1][j+1])%100003;
        /**
        for(int i=1;i<=n+1;i++)
        {
            for(int j=1;j<=2*n+1;j++)
                g<<a[i][j]<<" ";
            g<<'\n';
        }
        **/
        mancare(1,k);
        g<<s<<'\n';
    }
    return 0;
}
