#include <fstream>
using namespace std;
ifstream f("fractii2.in");
ofstream g("fractii2.out");
int c1[200],n,p;
float s;
int main()
{
    f>>p;
    f>>n;
    for(int i=1;i<=n-1;i++)
        g<<i<<" ";
    g<<n-1;
    return 0;
}
