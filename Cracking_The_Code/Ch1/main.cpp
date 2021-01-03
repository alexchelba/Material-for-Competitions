#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/// 1.6
/** /// varianta 1
int a[101][101],n,b[101][101];
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        f>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
    //int i=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        b[j][n-i+1]=a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            g<<a[n-j+1][i]<<" ";
        g<<'\n';
    }
    return 0;
}
**/

/** /// varianta 2
int a[101][101],n,b[101][101];
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        f>>a[i][j];
    for(int rama=1;rama<=n/2;rama++){
        int first_elem = rama;
        int last_elem = n-rama+1;
        for(int i=first_elem;i<last_elem;i++){
            int offset = i - first_elem;
            int top = a[first_elem][i];

            /// left -> top
            a[first_elem][i] = a[last_elem - offset][first_elem];

            /// bottom -> left
            a[last_elem-offset][first_elem] = a[last_elem][last_elem-offset];

            /// right -> bottom
            a[last_elem][last_elem-offset] = a[i][last_elem];

            /// top -> right
            a[i][last_elem] = top;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g<<a[i][j]<<" ";
        }
        g<<'\n';
    }
    return 0;
}
**/

