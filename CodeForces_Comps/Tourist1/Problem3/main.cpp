#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
int n,x,y,z,mark[50005];
typedef long double ld;
typedef tuple<ld,ld,ld> tpl;
vector<tpl> v;
ld dist(const tpl&a, const tpl&b)
{
    ld x,y,z;
    tie(x,y,z)=a;
    ld m,n,p;
    tie(m,n,p)=b;
    return sqrt((m-x)*(m-x)+(n-y)*(n-y)+(p-z)*(p-z));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        v.push_back(tpl(x,y,z));
    }
    for(int i=0;i<v.size();i++)
    {
        if(!mark[i])
        {
            mark[i]=1;
            int x,y,z;
            tie(x,y,z)=v[i];
            ld minn=0x3f3f3f3f;
            int pos=-1;
            for(int j=i+1;j<v.size();j++)
            {
                if(!mark[j]&&dist(v[i],v[j])<minn)
                {
                    minn=dist(v[i],v[j]);
                    pos=j;
                }
            }
            mark[pos]=1;
            cout<<i+1<<" "<<pos+1<<'\n';
        }
    }
    return 0;
}
