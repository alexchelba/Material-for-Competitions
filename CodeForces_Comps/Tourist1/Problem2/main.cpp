#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
int n, x;
map<int,int> entry,exitt;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        entry.insert({i,x});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        exitt.insert({x,i});
    }
    map<int,int>::iterator it = entry.begin();
    int maxx=0, nr=0;
    for(it;it!=entry.end();it++)
    {
        int aux=it->second;
        if(exitt.at(aux)<maxx) nr++;
            else maxx=exitt.at(aux);
    }
    cout<<nr<<'\n';
    return 0;
}
