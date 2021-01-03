/// 50 pct
#include<bits/stdc++.h>
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
struct muchie {int x,y;};
int t1,t2,n;//cardinalele si nr total de noduri
int T[10001],X[10001];//T vector TATA din BFS,X coada din BFS
muchie S[10001];//solutia
int sk;//lungimea solutiei
vector<int> V[10001];//listele de adiacenta

int BFS()//return 1 daca gaseste drum de crestere de la 0 la n
{
    int s=1,d=1,j;
    memset(T,0,sizeof(T));
    memset(X,0,sizeof(X));
    X[1]=0;T[0]=-1;//NODUL 0
    while(s<=d)
    {
        for(int i=0;i<V[X[s]].size();i++)
        {
            j=V[X[s]][i];
            if(T[j]==0)
            {
                X[++d]=j;
                T[j]=X[s];
                if(j==n)
                    return 1;
            }
        }
        s++;
    }
    return 0;
}
void cuplaj_maxim()
{
    int j;
    while(BFS())//cat timp mai gaseste drumuri de crestere
    {
        j=n;
        while(j!=0)//inverseaza arcele
        {
            for(int i=0;i<V[T[j]].size();i++)
            if(V[T[j]][i]==j)
                V[T[j]].erase(V[T[j]].begin()+i);
                V[j].push_back(T[j]);
                j=T[j];
        }
    }
}
int main()
{
    int i,x,y,m;
    f>>t1>>t2>>m;
    n=t1+t2;
    for(i=1;i<=t1;i++) V[0].push_back(i);//ADAUGA NOD DE START
    for(i=1;i<=m;++i)
    {
        f>>x>>y;
        V[x].push_back(y+t1);
    }
    n++;
    for(i=1;i<=t2;i++) V[t1+i].push_back(n);//ADAUGA NOD DESTINATIE
    cuplaj_maxim();
    for(i=0;i<V[n].size();i++)
        S[++sk].y=V[n][i];
    for(i=1;i<=sk;i++)
        S[i].x=V[S[i].y][V[S[i].y].size()-1];
    g<<sk<<endl;
    for(i=1;i<=sk;i++) g<<S[i].x<<" "<<S[i].y-t1<<endl;
    return 0;
}
