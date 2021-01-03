#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/** /// problema 1
struct nod{
    int val;
    nod *st, *dr;
};
int x;
nod *creare(){
    f>>x; nod *arb;
    if(!x) return NULL;
    arb=new nod;
    arb->val=x;
    arb->st=creare();
    arb->dr=creare();
    return arb;
}
void afis(nod *p){
    if(p){
        g<<p->val<<" ";
        afis(p->st);
        afis(p->dr);
    }
}
int main()
{
    nod *rad = creare();
    afis(rad);
    return 0;
}
**/

/** /// problema 2
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val)
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
void afis(nod *p){
    if(p){
        afis(p->st);
        if(p->niv%2==0) g<<p->val<<'\n';
        afis(p->dr);
    }
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    afis(rad);
    return 0;
}
**/

/** /// problema 3
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
int maxx;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val)
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
int afis(nod *p){
    if(p){
        if(p->niv>maxx) maxx=p->niv;
        afis(p->st);
        afis(p->dr);
    }
    return maxx;
}
int adancime(nod *p){
    if(p->val==NULL) return 1;
    int a = 1 + adancime(p->st);
    int b = 1 + adancime(p->dr);
    if(a>b) return a;
    return b;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    g<<afis(rad)<<'\n';
    return 0;
}
**/

/** /// problema 4
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val)
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
void afis(nod *p){
    if(p){
        afis(p->st);
        afis(p->dr);
        if(p->st&&p->dr) g<<p->val<<" ";
    }
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    afis(rad);
    return 0;
}
**/

/** /// problema 5
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
struct mima{
    int maxx, minn;
    mima(){
        maxx=0;
        minn=2000000;
    }
};
mima mo;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val)
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
mima afis(nod *p){
    if(p){
        if(p->val>mo.maxx) mo.maxx=p->val;
        if(p->val<mo.minn) mo.minn=p->val;
        afis(p->st);
        afis(p->dr);
    }
    return mo;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    mima mu = afis(rad);
    g<<mo.minn<<" "<<mo.maxx<<'\n';
    return 0;
}
**/

/** /// problema 6
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *arb;
int s;
void creare(int x, int niv, nod *&q){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!q) q=p;
    else{
        if(x<q->val)
            if(q->st) creare(x,q->niv+1,q->st);
                else {p->niv = q->niv+1; q->st=p;}
        else
            if(q->dr) creare(x,q->niv+1,q->dr);
                else {p->niv = q->niv+1; q->dr=p;}
    }
}
int afis(nod *p, int k){
    if(p){
        if(p->niv==k) s+=p->val;
        afis(p->st,k);
        afis(p->dr,k);
    }
    return s;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,0,arb);
    }
    int k;
    f>>k;
    g<<afis(arb,k);
    return 0;
}
**/

/** /// problema 7
struct nod{
    int val, niv;
    nod *st, *dr, *prev;
};
nod *arb;
int s;
void creare(int x, int niv, nod *&q){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->prev = NULL;
    p->st = NULL;
    p->dr = NULL;
    if(!q) q=p;
    else{
        if(x<q->val)
            if(q->st) creare(x,q->niv+1,q->st);
                else {p->niv = q->niv+1; p->prev=q; q->st=p;}
        else
            if(q->dr) creare(x,q->niv+1,q->dr);
                else {p->niv = q->niv+1; p->prev=q; q->dr=p;}
    }
}
void sterg(nod *&p){
    if(p){
        if(!p->st&&!p->dr) {nod *w = p->prev; if(w->dr==p) w->dr = NULL; else w->st = NULL; delete p;}
        else{
            sterg(p->st);
            sterg(p->dr);
        }
    }
}
void afis(nod *p){
    if(p){
        g<<p->val<<" ";
        afis(p->st);
        afis(p->dr);
    }
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,0,arb);
    }
    afis(arb);
    g<<'\n';
    sterg(arb);
    afis(arb);
    return 0;
}
**/

/** /// problema 8
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
int viz[100],maxx;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val)
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
int verif(nod *p){
    if(p){
        viz[p->niv]++;
        if(p->niv>maxx) maxx=p->niv;
        verif(p->st);
        verif(p->dr);
    }
    for(int i=0;i<=maxx;i++)
        if(viz[i]!=pow(2,i)) return 0;
    return 1;
}
int ver(nod *p){
    if(p->st&&!p->dr) return 0;
    if(p->dr&&!p->st) return 0;
    a = ver(p->st);
    b = ver(p->dr);
    return a&b;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    g<<verif(rad);
    return 0;
}
**/

/** /// problema 9
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *arb;
int s;
void creare(int x, int niv, nod *&q){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!q) q=p;
    else{
        if(x<q->val)
            if(q->st) creare(x,q->niv+1,q->st);
                else {p->niv = q->niv+1; q->st=p;}
        else
            if(q->dr) creare(x,q->niv+1,q->dr);
                else {p->niv = q->niv+1; q->dr=p;}
    }
}
int afis(nod *p, int k){
    if(p){
        if(p->niv==k&&!p->st&&!p->dr) s++;
        afis(p->st,k);
        afis(p->dr,k);
    }
    return s;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,0,arb);
    }
    int k;
    f>>k;
    g<<afis(arb,k);
    return 0;
}
**/

/// problema 10
struct nod{
    int val, niv;
    nod *st, *dr;
};
nod *rad;
int ok;
void creare(int x, int niv, nod *&b){
    nod *p = new nod;
    p->val = x;
    p->niv = niv;
    p->st = NULL;
    p->dr = NULL;
    if(!b) b = p;
    else{
        if(x<b->val){
            if(b->st) creare(x,niv+1,b->st);
            else {p->niv = b->niv+1; b->st=p;}
        }
        else{
            if(b->dr) creare(x,niv+1,b->dr);
            else {p->niv = b->niv+1; b->dr=p;}
        }
    }
}
int verif(nod *p){
    if(p){
        if(p->st&&p->val == p->st->val+1) return 1;
        if(p->dr&& p->dr->val == p->val+1) return 1;
        return verif(p->st)|verif(p->dr);
    }
    return 0;
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x, 0, rad);
    }
    g<<verif(rad);
    return 0;
}
