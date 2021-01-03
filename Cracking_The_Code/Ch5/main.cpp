#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/** /// move m into n starting at position j and ending at position i (j>i, but we are in bits).
int n,m;
int i,j;
int main()
{
    f>>n>>m;
    f>>i>>j;
    int x = n | m;
    x = x<<i;
    g<<x<<'\n';
    /**
    /// rezolvarea lor
    int maxx = ~0; /// All 1’s
    /// 1’s through position j, then 0’s
    int left = maxx - ((1 << j) - 1);
    /// 1’s after position i
    int right = ((1 << i) - 1);
    /// 1’s, with 0s between i and j
    int mask = left | right;
    /// Clear i through j, then put m in there
    int y = (n & mask) | (m << i);
    g<<y;

    return 0;
}
**/

/**
/// given a decimal number (eg. 3.72), find its binary representation. print an error in case it can't be accurately represented
string k;
double n;
int main()
{
    f>>k;
    n = strtod((k).c_str(), 0);
    g<<n<<'\n';
    int m = (int) n;
    double p = n - m;
    string s1 = "";
    while(m)
    {
        int c = m%2;
        m = m/2;
        char c1 = c + '0';
        s1 = c1 + s1;
    }
    g<<s1<<'.';
    char *b = reinterpret_cast<char*> (&p);
    for(size_t i = 0; i <= sizeof b; i++)
        g<<bitset<8>(b[i]);
    g<<'\n';
    char *v = reinterpret_cast<char*> (&n);
    for(size_t i = 0; i <= sizeof v; i++)
        g<<bitset<8>(v[i]);
    return 0;
}
**/

/// find the smallest no. greater than and the largest no. smaller than n with same number of bits
int n;
int main()
{
    f>>n;
    int *p = reinterpret_cast<int*>(&n);
    int ok = 0, nr = 0;
    size_t pos = 0;
    /// smallest no. greater than n, with same no. of bits
    bitset<32> a = bitset<32>(n);
    g<<a<<'\n';
    for(size_t i = 0; i <= sizeof a + 1; i++)
    {
        if(a[i] & 1) {ok=1; nr++;}
        else
        {
            if(ok) {a[i] = a[i] | 1; a[i-1] = a[i-1] & 0; pos = i-1; nr--; break;}
        }
    }
    size_t i=0;
    while(nr){pos--; a[pos] = a[pos]&0; a[i] = a[i]|1; i++; nr--;}
    g<<a<<'\n';

    /// largest no. smaller than n, with same no. of bits
    bitset<32> b = bitset<32>(n);
    ok=0; nr=0;
    for(i = sizeof b; i>=0;i--)
    {
        if(b[i] & 1) if(ok) nr++;

    }
    return 0;
}
