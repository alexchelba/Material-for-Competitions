#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
ifstream f("compresie.in");
ofstream g("compresie.out");
char s[1000001],a[1001][1001];
int nr,l,k,j,n;
void reconstr(short x1,short y1, short x2, short y2)
{
    short mx,my,x,i,j;
    if(x1<=x2&&y1<=y2&&k<l)
    {
        if(x1==x2&&y1==y2) a[x1][y1]=s[k++];
        else
        if(s[k]>='0'&&s[k]<='9')
            {
                x=0;
                while(s[k]>='0'&&s[k]<='9')
                {
                    x=x*10+(s[k]-'0');
                    k++;
                }
                for(i=x1;i<=x2;i++)
                for (j=y1;j<=y2;j++)
                    a[i][j]=s[k];
                k++;
            }
        else
            {
                mx=(x2+x1)/2; my=(y2+y1)/2;
                k++;
                reconstr(x1,y1,mx,my);
                reconstr(x1,my+1,mx,y2);
                reconstr(mx+1,y1,x2,my);
                reconstr(mx+1, my+1,x2,y2);
            }
    }
}

int main()
{
    f.getline(s,1000001);
    l=strlen(s);
    for(int i=0;i<=l;i++)
    {
        if(s[i]=='*') nr++;
        else
        if(s[i]>='0'&&s[i]<='9') k=k*10+(s[i]-'0');
        else
        if(s[i]>='a'&&s[i]<='z')
        {
            if(s[i-1]<'a'&&k)
            {
                j+=k;
                k=0;
            }
            else
            j++;
        }
    }
    n=sqrt(j);
    g<<nr<<endl;
    reconstr(1,1,n,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[i][j];
        g<<endl;
    }
    return 0;
}
