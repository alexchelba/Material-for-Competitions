#include <bits/stdc++.h>
#define inf 100001
using namespace std;
ifstream f("rfinv.in");
ofstream g("rfinv.out");
int t,n,m,a[55][55],b[55][55];
int main()
{
    f>>t;
    for(int q=1;q<=t;q++){
        f>>n>>m;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=inf;
            if(i==j) a[i][j]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            f>>x>>y;
            a[x][y]=1;
            a[y][x]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f>>b[i][j];
                if(a[i][j]==1) a[i][j]=b[i][j];
            }
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
        int ok=1;
        for(int i=1;i<=n&&ok;i++)
            for(int j=1;j<=n&&ok;j++)
            if(a[i][j]!=b[i][j]) ok=0;
        if(ok) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
