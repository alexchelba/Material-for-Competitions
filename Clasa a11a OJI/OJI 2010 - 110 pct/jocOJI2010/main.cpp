#include <fstream>
using namespace std;
ifstream f("joc13.in");
ofstream g("joc13.out");
int n,k,a[3][5005],pr,viz[3][5005],s1,s2;
void backt1(int i, int j)
{
    if(i<=2&&j<=n)
    {
        if(i==2) pr=1; else if(i==1) pr=2;
        if((j==n&&i==1)||(i==2&&j==n-1)) {s1+=a[2][n];}
        else
        if(a[pr][j]>=a[i][j+1])
        {
            if(!viz[pr][j]) {viz[pr][j]=1; s1+=a[pr][j]; backt1(pr,j);}
            else {viz[i][j+1]=1; s1+=a[i][j+1]; backt1(i,j+1);}
        }
        else
        if(a[i][j+1]>a[pr][j])
        {
            if(!viz[i][j+1]) {viz[i][j+1]=1; s1+=a[i][j+1]; backt1(i,j+1);}
            else {viz[pr][j]=1; s1+=a[pr][j]; backt1(pr,j);}
        }
    }
}
void backt2(int i, int j)
{
    if(i>=1&&j>=1)
    {
        if(i==2) pr=1; else if(i==1) pr=2;
        if((i==2&&j==1)||(i==1&&j==2&&viz[2][2])) {s2+=a[1][1];}
        else
        if(a[pr][j]>=a[i][j-1])
        {
            if(!viz[pr][j]) {viz[pr][j]=1; s2+=a[pr][j]; backt2(pr,j);}
            else {viz[i][j-1]=1; s2+=a[i][j-1]; backt2(i,j-1);}
        }
        else
        if(a[pr][j]<a[i][j-1])
        {
            if(!viz[i][j-1]) {viz[i][j-1]=1; s2+=a[i][j-1]; backt2(i,j-1);}
            else {viz[pr][j]=1; s2+=a[pr][j]; backt2(pr,j);}
        }
    }
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];
    viz[1][1]=1;
    s1=a[1][1];
    backt1(1,1);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
        viz[i][j]=0;
    viz[2][n]=1;
    s2=a[2][n];
    backt2(2,n);
    if(s1<s2) g<<s2<<'\n';
    else g<<s1<<'\n';
    f.close();
    g.close();
    return 0;
}
