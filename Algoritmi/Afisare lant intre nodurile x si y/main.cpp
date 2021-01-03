#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int A[50][50];
int n,m;
int p[50],X[50],x,y;

void citire()
{
   int p,q,i;
   fin>>n>>m;
   for(i=1;i<=m;i++)
   {
       fin>>p>>q;
       A[p][q]=A[q][p]=1;
   }
   fin>>x>>y;
}

void afis(int k)
{
    for(int i=1;i<=k;i++) fout<<X[i]<<" ";
    fout<<endl;
}

void backr(int k)
{
    for(int i=1;i<=n;i++)
        if(!p[i] && A[X[k-1]][i]==1)
        {
            X[k]=i;
            p[i]=1;
            if(i==y) afis(k);
            else backr(k+1);
            p[i]=0;
        }
}
int main()
{
    citire();
    X[1]=x;
    p[x]=1;
    backr(2);
    fin.close();
    fout.close();
    return 0;
}
