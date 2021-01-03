#include<bits/stdc++.h>
#define MIN 1e9
using namespace std;
ifstream f("insule.in");
ofstream g("insule.out");
struct lees
{
    int x,y,val;
};
int n,m,b[150][150],viz[150][150];
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
char s[150][150];
queue<lees> q;
void fills(int i, int j, int k)
{
    if(b[i][j]==k&&!viz[i][j])
    {
        if(k==1) q.push({i,j,0});
        viz[i][j]=1;
        fills(i+1,j,k);
        fills(i,j+1,k);
        fills(i-1,j,k);
        fills(i,j-1,k);
    }
}
int lee()
{
    while(q.size())
    {
        lees w = q.front();
        q.pop();
        for(int k=0;k<4;k++)
        if(b[w.x+dl[k]][w.y+dc[k]]==0)
        {
            b[w.x+dl[k]][w.y+dc[k]]=3;
            q.push({w.x+dl[k], w.y+dc[k], w.val+1});
        }
        else
        if(b[w.x+dl[k]][w.y+dc[k]]==2&&w.val) return w.val;
    }
    return MIN;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f.get();
        f.get(s[i],101);
        for(int j=1;j<=m;j++)
            b[i][j]=s[i][j-1]-'0';
    }
    for(int k=1;k<=3;k++)
    {
        int nr=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                if(b[i][j]==k&&!viz[i][j]) {nr++; fills(i,j,k);}
            }
        g<<nr<<" ";
    }
    for(int k=0;k<=n+1;k++)
    {
        b[k][0]=3; b[k][m+1]=3;
    }
    for(int p=0;p<=m+1;p++)
    {
        b[0][p]=3; b[n+1][p]=3;
    }
    g<<lee();
    return 0;
}
