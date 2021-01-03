#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct interval
{
    int stn,drt;
};
struct itnode
{
    interval *i;
    int maxim;
    itnode *stanga, *dreapta;
};
itnode * newnode(interval i)
{
    itnode *temp= new itnode;
    temp->i=new interval(i);
    temp->maxim=i.drt;
    temp->stanga=temp->dreapta=NULL;
}
itnode *introduce(itnode *radacina, interval i)
{
    if(radacina==NULL) return newnode(i);
    int l=radacina->i->stn;
    if(i.stn<l) radacina->stanga=introduce(radacina->stanga,i);
    else radacina->dreapta=introduce(radacina->dreapta,i);
    if(radacina->maxim<i.drt) radacina->maxim=i.drt;
    return radacina;
}
bool intersecteaza(interval i1, interval i2)
{
    if(i1.stn<=i2.drt&&i2.stn<=i1.drt)
        return 1;
    return 0;
}
interval *cauta(itnode *radacina, interval i)
{
    if(radacina==NULL) return NULL;
    if(intersecteaza(*(radacina->i),i))
        return radacina->i;
    if(radacina->stanga!=NULL&&radacina->stanga->maxim>=i.stn)
        return cauta(radacina->stanga,i);
    return cauta(radacina->dreapta,i);
}
void inordine(itnode *radacina)
{
    if(radacina==NULL) return ;
    inordine(radacina->stanga);
    g<<radacina->i->stn<<" "<<radacina->i->drt<<" "<<radacina->maxim<<'\n';
    inordine(radacina->dreapta);
}
int n,q;
int main()
{
    f>>n>>q;
    itnode *radacina=NULL;
    for(int i=1;i<=n;i++)
    {
        interval a;
        f>>a.stn>>a.drt;
        radacina=introduce(radacina,a);
    }
    inordine(radacina);
    for(int i=1;i<=q;i++)
    {
        interval b;
        f>>b.stn>>b.drt;
        g<<"intersectie "<<b.stn<<" "<<b.drt<<'\n';
        interval *res=cauta(radacina,b);
        if(res==NULL) g<<"nu se intersecteaza"<<'\n';
        if(res) {g<<res->stn<<" "<<res->drt<<'\n';}
    }
    return 0;
}
