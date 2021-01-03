#include <bits/stdc++.h>
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
char s[5][50001],s1[50001];
int viz[50001],n,m,poz,minn=2000000,maxx=0;
int main()
{
    f>>n;
    f.get();
    for(int i=1;i<=n;i++)
    {
        f.getline(s[i],10001);
    }
    for(int i=1;i<=n;i++)
    {
        int n1=strlen(s[i])-1;
        if(n1<minn) {minn=n1; poz=i;}
    }
    m=strlen(s[poz])-1;
    for(int i=0;i<=m;i++)
        viz[i]=1;
    /**
    for(int i=0;i<=m;i++)
        g<<viz[i]<<" ";
   **/
    int j=0, ok1=1, ok2=1;
    do
    {
        ///g<<s[poz]<<'\n';
        int i=m-j;
        while(i&&ok1)
        {
            ///g<<i<<" ";
            ///g<<s[poz]<<" ";
            strncpy(s1,s[poz],i+1); s1[i+2]=NULL;
            int ok=1;
            for(int k=1;k<=n&&ok;k++)
                if(k!=poz&&!strstr(s[k],s1)) ok=0;
            if(ok) if(strlen(s1)>maxx)
            {
                maxx=strlen(s1);
            ///g<<s1<<" "<<1<<'\n';
            }
            ///else g<<s1<<'\n';
            i--;
        }
        ///g<<'\n';
        strcpy(s[poz],s[poz]+1);
        j++;
        if(j==m) ok2=0;
    }while(ok2);
    g<<maxx<<'\n';
    return 0;
}
