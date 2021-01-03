#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("date.in");
int n,v,s[100],t[100],d[100];
long int pinf=1000000000,min1;

struct nod{
    int nr,m;
    nod *urm;
};
nod *a[100];

void citire()
{
    f>>n>>v;
    int v1,v2,val;
    while(f>>v1>>v2>>val)
    {
        nod *q,*c;
        q=new nod;
        q->nr=v2;
        q->m=val;
        q->urm=NULL;
        if(!a[v1])
            a[v1]=q;
        else
        {
            c=a[v1];
            while(c->urm)
                c=c->urm;
            c->urm=q;
        }
    }
}

void cauta_min(int &vf)
{
    min1=pinf;
    for(int i=1;i<=n;i++)
        if(!s[i])
            if(d[i]<min1)
            {
                min1=d[i];
                vf=i;
            }
}

void imbunatatire(int vf)
{
    for(int i=1;i<=n;i++)
        if(!s[i])
        {
            int val1; val1=pinf;
            nod *p;
            p=a[vf];
            while(p)
            {
                if(p->nr==i)
                    val1=p->m;
                p=p->urm;
            }

            if(d[i]>d[vf]+val1)
            {
                d[i]=d[vf]+val1;
                t[i]=vf;
            }
        }
}

void drum(int i)
{
    if(t[i])
        drum(t[i]);
    cout<<i<<" ";
}

void afis_vector(int ve[100])
{
    for(int i=1;i<=n;i++)
        cout<<ve[i]<<" ";
    cout<<endl;
}

int main()
{
    citire();
    int vf,min1;
    for(int i=1;i<=n;i++)
        if(i!=v)
        {
            nod *p;
            int val1;
            p=a[v];
            while(p && p->nr!=i)
                p=p->urm;
            if(!p)
                val1=pinf;
            else
                val1=p->m;
            d[i]=val1;
            if(val1!=pinf)
                t[i]=v;
        }
    for(int k=1;k<=n-1;k++)
    {
        cauta_min(vf);
        s[vf]=1;
        imbunatatire(vf);
    }
    cout<<"Drum ";afis_vector(d);
    //cout<<"Noduri vizitate ";afis_vector(s);
    //cout<<"Tati ";afis_vector(t);
    return 0;
}
