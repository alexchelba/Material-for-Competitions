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
/// LSU ce contine cifrele numarului dat
/**
void push_dub(int x){
    if(!dub_inc){
        dub_inc = new nod;
        dub_inc->val = x;
        dub_inc->urm = NULL;
        dub_inc->bacc = NULL;
        dub_sf = dub_inc;
    }
    else{
        nod *c;
        c = new nod;
        c->val = x;
        c->urm = NULL;
        c->bacc = dub_sf;
        dub_sf->urm = c;
        dub_sf = c;
    }
}
**/
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
/**
void sterg(nod *&p){
    /**nod *c = new nod;
    nod *d = new nod;
    c=p->bacc;
    d=p->urm;
    if(c) c->urm=d;
    if(d) d->bacc=c;
    delete c;
    **/
    /**nod *x=new nod;
    x=p;
    p=p->urm;
    if(p) p->bacc = x->bacc;
    delete x;
}**/
void adaugprim(int x){
    if(!dub_inc){
        dub_inc = new nod;
        dub_inc->val = x;
        dub_inc->urm = NULL;
        dub_inc->bacc = NULL;
        dub_sf = dub_inc;
    }
    else {
        nod *p;
        p = new nod;
        p->val = dub_inc->val;
        p->urm = dub_inc->urm;
        p->bacc = dub_inc;
        dub_inc->val=x;
        if(dub_inc->urm) dub_inc->urm->bacc = p;
        dub_inc->urm = p;
        if(!p->urm) dub_sf=p;
    }
}
void adaug(int x){
    nod *p = dub_inc;
    while(p->urm && x>p->urm->val){
        p=p->urm;
    }
    nod *q = new nod;
    q->urm = p->urm;
    if(p->urm) p->urm->bacc=q;
    q->bacc = p;
    p->urm = q;
    q->val=x;
    if(!q->urm) dub_sf=q;
}
int main()
{
    int n;
    f>>n;
    int c;
    while(n){
        c=n%10;
        n=n/10;
        if(!dub_inc||c<dub_inc->val) adaugprim(c);
        else adaug(c);
    }
    g<<"dub:\n"; afis_dub();
    /**nod *c1; c1 = dub_inc;
    while(c1){
        if(c1->val==2)
            sterg(c1);
        else
            c1=c1->urm;
    }**/
    g<<"dubsters:\n"; afis_dub();
    return 0;
}
