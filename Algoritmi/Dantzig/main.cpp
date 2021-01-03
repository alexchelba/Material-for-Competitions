#include<bits/stdc++.h>
#define N 50
#define INF 0x3f3f3f3f
using namespace std;
ifstream f("dantzig.in");
ofstream g("dantzig.out");
int a[N][N],b[N][N],d[N],st[N],sos,p;
int sel[N],n,minn,k;
void citire()
{
	int i,j,x,y,z;
	f>>n>>p;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) { a[i][j]=INF; b[i][j]=INF; }
		for(i=1;i<=n;i++) { a[i][i]=0; b[i][i]=0; }
	while(!f.eof())
	{	f>>x>>y>>z;
		a[x][y]=z;
	}
}
void minim()
{
    int i,j;
	minn=INF;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(sel[i]&&!sel[j])
				if(minn>d[i]+a[i][j])
				{
					minn=d[i]+a[i][j]; k=j;
				}
}
void dantzig()
{
    int i,j;
	for(i=1;i<=n-1;i++)
	{
		minim();
		if(minn!=INF)
		{
			sel[k]=1; d[k]=minn;
			for(j=1;j<=n;j++)
				if(sel[j]&&(d[j]+a[j][k]==minn)) b[j][k]=a[j][k];
		}
	}
}
void drum(int k)
{
    int i,j;
	for(i=1;i<=n;i++)
		if(b[st[k-1]][i]<INF && !sel[i])
		{
			if(i!=sos)
			{
				sel[i]=1; st[k]=i; drum(k+1); sel[i]=0;
			}
			else
			{
			    for(j=1;j<k;j++) g<<st[j]<<" ";
				g<<sos<<" de cost "<<d[sos]<<'\n';
			}
		}
}
int main()
{	int i;
	citire();
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
	sel[p]=1; d[p]=0;
	dantzig();
	for(sos=1;sos<=n;sos++)
		if(p!=sos)
		{
		    for(i=1;i<=n;i++) sel[i]=0;
			sel[p]=1; st[1]=p; drum(2);
        }
    drum(p);
    return 0;
}
