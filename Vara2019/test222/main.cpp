#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    int val;
    nod *urm;
    nod *bacc;
};
nod *dub_inc, *dub_sf;
/// LDU ce contine cifrele numarului dat
void afis_dub(){
    nod *c;
    c = dub_inc;
    while(c){
        g<<c->val<<" ";
        c = c->urm;
    }
    g<<'\n';
    c = dub_sf;
    while(c){
        g<<c->val<<" ";
        c = c->bacc;
    }
    g<<'\n';
}
void adaug(int x, nod *&dub, nod*&dub2)
{
    nod *p;
    p = new nod;
    p->val = dub->val;
    p->urm = dub2;
    p->bacc = dub;
    dub->val=x;
    dub2->bacc = p;
    dub->urm = p;
}
void adaug_sf(int x)
{
    g<<"dub " << dub_sf->val<<" "<<x<<'\n';
    nod *p;
    p = new nod;
    p->val = x;
    p->urm = dub_sf;
    p->bacc = dub_sf->bacc;
    if(dub_sf->bacc) dub_sf->bacc->urm=p; else dub_inc=p;
    //dub_sf->val=x;
    g<<"dub " << dub_sf->val<<" "<<p->val<<'\n';
}
void push_dub_ordonat(int x)
{
    if(!dub_inc){
        //g<<"x0 "<<x<<'\n';
        dub_inc = new nod;
        dub_inc->val = x;
        dub_inc->urm = NULL;
        dub_inc->bacc = NULL;
        dub_sf = dub_inc;
    }
    else
    if(x<dub_inc->val){
        //g<<"x "<<x<<'\n';
        nod *dub=dub_inc->urm;
        if(dub) adaug(x,dub_inc,dub);
        else adaug_sf(x);
    }
    else{
        //g<<"x2 "<<x<<'\n';
        nod *dub = dub_inc;
        while(dub && x<dub->val)
        {
            dub = dub->urm;
        }
        if(dub&&dub->urm)
        {
            nod *dub2 = dub->urm;
            adaug(x,dub,dub2);
        }
        else adaug_sf(x);
    }
}
int main()
{
    int n;
    f>>n;
    int c;
    while(n){
        c=n%10;
        n=n/10;
        push_dub_ordonat(c);
    }
    g<<"dub:\n"; afis_dub();
    return 0;
}
