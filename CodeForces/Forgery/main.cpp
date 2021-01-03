#include <iostream>
using namespace std;
int a[1005][1005], b[1005][1005],n,m;
char s[1005][1005];
void fill_from_center(int i, int j)
{
    if(i-1<=0) return ;
    if(i+1>n) return ;
    if(j-1<=0) return ;
    if(j+1>m) return ;
    a[i-1][j-1]=1; a[i-1][j]=1; a[i-1][j+1]=1;
    a[i][j-1]=1; a[i][j+1]=1;
    a[i+1][j-1]=1; a[i+1][j]=1; a[i+1][j+1]=1;
}
int check_from_center(int i, int j)
{
    if(i-1<=0) return 0;
    if(i+1>n) return 0;
    if(j-1<=0) return 0;
    if(j+1>m) return 0;
    if(b[i-1][j-1]==0 || b[i-1][j]==0 || b[i-1][j+1]==0 || b[i][j-1]==0 || b[i][j+1]==0 || b[i+1][j-1]==0 || b[i+1][j]==0 || b[i+1][j+1]==0)
        return 0;
    return 1;
}
void check_if_fillable(int i, int j)
{
    if(check_from_center(i-1,j-1)) fill_from_center(i-1,j-1);
    if(check_from_center(i-1,j)) fill_from_center(i-1,j);
    if(check_from_center(i-1,j+1)) fill_from_center(i-1,j+1);
    if(check_from_center(i,j-1)) fill_from_center(i,j-1);
    if(check_from_center(i,j+1)) fill_from_center(i,j+1);
    if(check_from_center(i+1,j-1)) fill_from_center(i+1,j-1);
    if(check_from_center(i+1,j)) fill_from_center(i+1,j);
    if(check_from_center(i+1,j)) fill_from_center(i+1,j);
}
int check_if_equal()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i][j]!=b[i][j]) return 0;
    return 1;
}
int main()
{
    cin>>n>>m;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        cin.getline(s[i],1000);
        for(int j=0;j<m;j++)
            if(s[i][j]=='#') b[i][j+1]=1;
    }

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(b[i][j]==0&&check_from_center(i,j)) fill_from_center(i,j);

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(a[i][j]==0&&b[i][j]==1) check_if_fillable(i,j);

    if(check_if_equal()) cout<<"YES"; else cout<<"NO";

    return 0;
}
