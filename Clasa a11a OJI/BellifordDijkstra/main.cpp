#include<bits/stdc++.h>
#define nmax 50002
#define INF 0x3f3f3f3f
using namespace std;
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
/** /// BelliFord
int n,m,x,y,cost,d[nmax],viz[nmax],ok;
vector<pair<int, int> > v[nmax];
queue<int> c;
int main()
{
	f>>n>>m;
	for(int i=1;i<=m;i++)
	{
		f>>x>>y>>cost;
		v[x].push_back(make_pair(y,cost));
	}
	memset(d,INF,sizeof(d));
	c.push(1);
	d[1]=0;
	while(!c.empty())
	{
		int w=c.front();
		c.pop();
		if(++viz[w]==n)
		{
			g<<"Ciclu negativ!"<<'\n';
			ok=1;
			break;
		}
		for(int i=0;i<v[w].size();i++)
			if(d[v[w][i].first]>d[w]+v[w][i].second)
			{
				d[v[w][i].first]=d[w]+v[w][i].second;
				c.push(v[w][i].first);
			}
	}
	if(!ok)
	for(int i=2;i<=n;i++)
        if(d[i]==INF) g<<"0 ";
    else
		g<<d[i]<<" ";
	return 0;
}
**/

int n,m,x,y,cost,d[nmax];
vector<pair<int, int> > v[nmax];
queue<int> c;
int main()
{
	f>>n>>m;
	for(int i=1;i<=m;i++)
	{
		f>>x>>y>>cost;
		v[x].push_back(make_pair(y,cost));
	}
	memset(d,INF,sizeof(d));
	c.push(1);
	d[1]=0;
	while(!c.empty())
	{
		int w=c.front();
		c.pop();
		for(int i=0;i<v[w].size();i++)
			if(d[v[w][i].first]>d[w]+v[w][i].second)
			{
				d[v[w][i].first]=d[w]+v[w][i].second;
				c.push(v[w][i].first);
			}
	}
	for(int i=2;i<=n;i++)
        if(d[i]==INF) g<<"0 ";
    else
		g<<d[i]<<" ";
	return 0;
}
