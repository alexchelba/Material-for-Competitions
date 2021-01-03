#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/**
int n,m,x,y,viz[1001];
vector<int> v[1000];
queue<int> q;
void dfs(int k){
    g<<k<<" ";
    for(int i=0;i<v[k].size();i++)
        if(!viz[v[k][i]]){
            viz[v[k][i]]=1;
            dfs(v[k][i]);
            viz[v[k][i]]=0;
        }
}
void bfs(int k){
    g<<k<<" ";
    q.pop();
    for(int i=0;i<v[k].size();i++)
        if(!viz[v[k][i]]){
            viz[v[k][i]]=1;
            q.push(v[k][i]);
        }
    if(q.front()) bfs(q.front());
}
void preordine(int k){
    if(!viz[k]){
        g<<k
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        v[x].push_back(y);
    }
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=0;j<v[i].size();j++)
    //        g<<v[i].at(j)<<" ";
    //    g<<'\n';
    //}
    viz[1]=1;
    dfs(1);
    g<<'\n';
    memset(viz,0,sizeof(viz));
    q.push(1);
    bfs(1);
    return 0;
}
**/

/**
typedef struct muchie{
    int inf, n;
    muchie *leg[30];
}ARB;
ARB *coada[100];
int prim,ultim;
ARB* creare()
{
	int info,nr,i; ARB *p;
    f>>info;
	p=new ARB; p->inf=info;
	f>>nr; p->n=nr;
	for(i=0;i<p->n;i++) p->leg[i]=creare();
	return p;
}
void preordine(ARB *p)
{
	int i;
	if(p)
	{
		g<<p->inf<<" ";
		for(i=0;i<p->n;i++) preordine(p->leg[i]);
	}
}
void postordine(ARB *p)
{
	int i;
	if(p)
	{
		for(i=0;i<p->n;i++)
			if(p->leg[i]) postordine(p->leg[i]);
        g<<p->inf<<" ";
	}
}
void adauga(ARB *p)
{
	if(prim>ultim) g<<"Coada este plina\n";
	else coada[ultim++]=p;
}
ARB* extrage_nod()
{
	if(prim==ultim) return 0;
	else return coada[prim++];
}
void traversare_nivele(ARB *rad)
{
	ARB *p; int i;
	prim=ultim=0;
	adauga(rad);
	do{
		p=extrage_nod();
		if(p)
		{
			g<<p->inf<<" ";
			for(i=0;i<p->n;i++)
				adauga(p->leg[i]);
		}
	}while(p);
	g<<"\n";
}
void sterge(ARB *p)
{
	int i;
	if(p)
		for(i=0;i<p->n;i++) sterge(p->leg[i]);
	delete p;
}
int main()
{
	ARB *rad;
	rad=creare();
	g<<"traversare in preordine ";
	preordine(rad);
	g<<"\n traversare in postordine ";
	postordine(rad);
	g<<"\n traversare in inordine ";
	traversare_nivele(rad);
	//sterge(rad);
    return 0;
}
**/

/**
int S[31],D[31],rad,n;
void SRD(int k)
{
	if(S[k]) SRD(S[k]);
	g<<k<<" ";
	if(D[k]) SRD(D[k]);
}
void RSD(int k)
{
	g<<k<<" ";
	if(S[k]) RSD(S[k]);
	if(D[k]) RSD(D[k]);
}
void SDR(int k)
{
	if(S[k]) SDR(S[k]);
	if(D[k]) SDR(D[k]);
	g<<k<<" ";
}
int main()
{
	int i;
	do{
		f>>n;
	}while(n<1||n>30);
	do{
		f>>rad;
	}while(rad<1||rad>n);
	for(i=1;i<=n;i++)
	{
		f>>S[i]>>D[i];
	}
	g<<"\n\tParcurgerea in preordine:\n";
	RSD(rad);
	g<<"\n\n\tParcurgerea in inordine:\n";
	SRD(rad);
	g<<"\n\n\tParcurgerea in postordine:\n";
	SDR(rad);
	g<<"\n";
return 0;
}
**/

typedef struct nod{
	int inf;
	nod *st,*dr;
}ARB;
void creare(ARB* &r)
{
	int x;
	f>>x;
	if(!x)
		r=0;
	else
	{
		r=new ARB; r->inf=x;
		creare(r->st); creare(r->dr);
	}
}
void SRD(ARB *r)
{
	if(r)
	{
		SRD(r->st); g<<r->inf<<" "; SRD(r->dr);
	}
}
void RSD(ARB *r)
{
	if(r)
	{
		g<<r->inf<<" "; RSD(r->st); RSD(r->dr);
	}
}
void SDR(ARB *r)
{
	if(r)
	{
		SDR(r->st); SDR(r->dr); g<<r->inf<<" ";
	}
}
void sterge(ARB *r)
{
	if(r)
	{
		sterge(r->st); sterge(r->dr); delete r;
	}
}
int main()
{rrrggg
	ARB *rad;
	creare(rad);
	g<<"\nNodurile in inordine:   "; SRD(rad);
	g<<"\nNodurile in preordine:  "; RSD(rad);
	g<<"\nNodurile in postordine: "; SDR(rad);
	g<<"\n";
	sterge(rad);  //stergerea arborelui din heap
    return 0;
}

/// AVL - arbore binar de cautare echilibrat, intervale, rosu-negru, centroizi, LCA
