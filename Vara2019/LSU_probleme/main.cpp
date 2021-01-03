#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/**
struct nod
{
    int val;
    nod *urm;
    nod *bacc;
};
nod *ls_inc, *ls_sf, *st, *dub_inc, *dub_sf;
/// LSU ce contine cifrele numarului dat
void push_ls(int x){
    if(!ls_inc){
        ls_inc = new nod;
        ls_inc->val = x;
        ls_inc->urm = NULL;
        ls_sf=ls_inc;
    }
    else{
        nod *c;
        c = new nod;
        c->val = x;
        c->urm = NULL;
        ls_sf->urm = c;
        ls_sf = c;
    }
}
void push_stiva(int x){
    if(!st){
        st = new nod;
        st->val = x;
        st->urm = NULL;
    }
    else{
        nod *c;
        c = new nod;
        c->val = x;
        c->urm = st;
        st=c;
    }
}
void afis_sf(){
    nod *c;
    c = ls_inc;
    while(c){
        g<<c->val<<" ";
        c=c->urm;
    }
    g<<'\n';
}
void afis_inc(){
    nod *c;
    c = st;
    while(c){
        g<<c->val<<" ";
        c=c->urm;
    }
    g<<'\n';
}
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
int main()
{
    int n;
    f>>n;
    int c;
    while(n){
        c=n%10;
        n=n/10;
        push_ls(c);
        push_stiva(c);
        push_dub(c);
    }
    g<<"sf: "; afis_sf();
    g<<"inc: "; afis_inc();
    g<<"dub:\n"; afis_dub();
    return 0;
}
**/

struct nod
{
    int val;
    nod *urm;
};
nod *ls_par, *ls_imp, *ls1, *ls2, *ls3;
void push(nod *&ls, int x){
    if(!ls){
        ls = new nod;
        ls->val = x;
        ls->urm = NULL;
    }
    else{
        nod *c;
        c = new nod;
        c->val = x;
        c->urm = ls;
        ls = c;
    }
}
void afis(nod *ls){
    while(ls){
        g<<ls->val<<" ";
        ls = ls->urm;
    }
    g<<'\n';
}
void intersectie(){
    nod *c = new nod;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int a;
        f>>a;
        push(ls1,a);
        if(a%2==0) push(ls_par,a);
        else push(ls_imp,a);
    }
    int m;
    f>>m;
    for(int i=1;i<=m;i++){
        int b;
        f>>b;
        push(ls2,b);
    }
    afis(ls_imp);
    afis(ls_par);

    return 0;
}
