#include <bits/stdc++.h>
#define nmax 1005
#define INF 0x3f3f3f3f
using namespace std;
ifstream f("ciclu.in");
ofstream g("ciclu.out");
struct data{
    int nod, ciclu, timp;
};
int n,m,x,y,cost,d[nmax],ok;
vector<pair<int, int> > v[nmax];
double bellman_ford(int nod){
    queue<data> c;
    memset(d,INF,sizeof(d));
    double rez=INF;
	d[nod]=0;
	data x,y;
	x.nod=nod;
	x.ciclu=1;
	x.timp=0;
	c.push(x);
	while(!c.empty())
	{
        x=c.front();
		c.pop();
		for(int i=0;i<v[x.nod].size();i++){
		    y.nod=v[x.nod][i].first;
            y.timp=x.timp+v[x.nod][i].second;
            y.ciclu=x.ciclu+1;
            if(y.nod==nod){
                double t=y.timp;
                double nr=x.ciclu;
                rez=min(rez,(double)t/nr);
                continue;
            }
			if(d[y.nod]>y.timp)
			{
				d[y.nod]=y.timp;
				c.push(y);
			}
		}
	}
	return rez;
}
int main()
{
	f>>n>>m;
	for(int i=1;i<=m;i++)
	{
		f>>x>>y>>cost;
		v[x].push_back(make_pair(y,cost));
	}
	double rez=INF;
	for(int i=1;i<=n;i++){
        rez=min(rez, bellman_ford(i));
	}
	g<<fixed<<setprecision(2)<<rez<<'\n';
	return 0;
}
