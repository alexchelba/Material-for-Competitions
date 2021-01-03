#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/** /// problema 19
struct nod{
    int val;
    nod *urm;
};
nod *prim, *ultim;
nod* make(int x){
    if(!prim){
        nod *p = new nod;
        p->val = x;
        p->urm = NULL;
        prim=p;
        ultim=p;
    }
    else{
        nod *p = new nod;
        p->val=x;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;
    }
    return prim;
}
void del(nod *&prim){
    if(!prim||!prim->urm) return;
    if(prim->val==prim->urm->val){
        nod *p=prim;
        prim=prim->urm;
        delete p;
        nod *b=prim;
        prim=prim->urm;
        delete p;
    }
    else{
        nod *p = prim->urm;
        nod *q = prim;
        while(p->urm){
            if(p->val==p->urm->val){
                nod *a=p;
                p=p->urm;
                q->urm=p;
                delete a;
                nod *b=p;
                if(p->urm) {p=p->urm; q->urm=p;} else q->urm=NULL;
                delete b;
            }
            else {q=q->urm; p=p->urm;}
        }
    }
    nod *p = prim;
    while(p){
        if(p->val==p->urm->val) del(prim);
        else p=p->urm;
    }
}
void print(nod *prim){
    nod *p = prim;
    while(p){
        g<<p->val<<" ";
        p=p->urm;
    }
}
int main()
{
    nod* p;
    int x;
    f>>x;
    if(x) p=make(x);
    while(x!=0){
        f>>x;
        if(x) p=make(x);
    }
    del(p);
    if(p) print(p); else g<<0<<'\n';
    return 0;
}
**/

/** /// problema 24
struct nod{
    char car;
    nod *urm;
    nod *prev;
};
nod *prim, *ultim;
nod *a_prim, *a_ultim, *b_prim, *b_ultim;
bool isAlpha(char x){
    if('a'<=x&&x<='z') return true;
    if('A'<=x&&x<='Z') return true;
    return false;
}
void adauga(char x){
    if(!prim){
        nod *p = new nod;
        p->prev=NULL;
        p->urm=NULL;
        p->car=x;
        prim=p;
        ultim=p;
    }
    else{
        nod *p = new nod;
        p->prev=ultim;
        ultim->urm=p;
        p->urm=NULL;
        p->car=x;
        ultim=p;
    }
}
void adauga_2_liste(nod *&prim, nod *&ultim, nod *p){
    if(!prim){
        p->urm=NULL;
        p->prev=NULL;
        prim=p;
        ultim=p;
    }
    else{
        p->prev=ultim;
        ultim->urm=p;
        p->urm=NULL;
        ultim=p;
    }
}
void afis(nod *pro){
    nod *p =pro;
    while(p){
        g<<p->car<<" ";
        p=p->urm;
    }
    g<<'\n';
}
int main(){
    char x;
    f>>x;
    while(x!='.'){
        if(x!='.') adauga(x);
        f>>x;
    }
    nod *p=prim;
    while(prim){
        p=prim;
        prim=prim->urm;
        if(isAlpha(p->car)) adauga_2_liste(a_prim, a_ultim, p);
        else adauga_2_liste(b_prim, b_ultim, p);
    }
    afis(a_prim);
    afis(b_prim);
    return 0;
}
**/

/** /// problema 25
struct nod{
    int a0, n;
    nod *urm, *prev;
};
nod *a_prim, *a_ultim, *b_prim, *b_ultim, *s_prim, *s_ultim, *p_prim, *p_ultim;
int nn,m;
void adauga(nod *&prim, nod *&ultim, int a, int x){
    if(!prim){
        nod *p = new nod;
        p->prev=NULL;
        p->urm=NULL;
        p->a0=a;
        p->n = x;
        prim=p;
        ultim=p;
    }
    else{
        nod *p = new nod;
        p->prev=ultim;
        ultim->urm=p;
        p->urm=NULL;
        p->a0=a;
        p->n = x;
        ultim=p;
    }
}
void suma(nod *prim1, nod *prim2, nod *&prim3, nod *&ultim3){
    nod *p = prim1;
    nod *q = prim2;
    nod *t = 0;
    nod *w = 0;
    while(p&&q){
        if(q&&p->n==q->n)
        {
            int s=p->a0+q->a0;
            adauga(prim3, ultim3, s,p->n);
            p=p->urm;
            q=q->urm;
        }
        else
        if(q&&p->n>q->n)
        {
            adauga(prim3, ultim3, p->a0,p->n);
            p=p->urm;
        }
        else
        if(q&&p->n<q->n)
        {
            adauga(prim3, ultim3, q->a0,q->n);
            q=q->urm;
        }
    }
    while(p)
    {
        adauga(prim3, ultim3, p->a0,p->n);
        p=p->urm;
    }
    while(q)
    {
        adauga(prim3, ultim3, q->a0,q->n);
        q=q->urm;
    }
}
nod *cauta(nod *&prim, int n1, int a){
    while(prim){
        if(prim->n == n1) {prim->a0+=a; return prim;}
        prim=prim->urm;
    }
    return NULL;
}
void produs(nod *prim1, nod *prim2, nod *&prim3, nod *&ultim3){
    while(prim1){
        nod *q=prim2;
        while(q){
            int grad = prim1->n + q->n;
            int coef = prim1->a0 * q->a0;
            nod *z = prim3;
            if(!cauta(z,grad,coef)) adauga(prim3,ultim3,coef,grad);
            q=q->urm;
        }
        prim1=prim1->urm;
    }
}
void afis(nod *prim){
    while(prim){
        g<<"("<<prim->a0<<", "<<prim->n<<") ";
        prim=prim->urm;
    }
    g<<'\n';
}
int main(){
    f>>nn;
    for(int i=1;i<=nn;i++){
        int a,x;
        f>>a>>x;
        adauga(a_prim,a_ultim,a,x);
    }
    f>>m;
    for(int i=1;i<=m;i++){
        int a,x;
        f>>a>>x;
        adauga(b_prim,b_ultim,a,x);
    }
    suma(a_prim,b_prim,s_prim,s_ultim);
    g<<"suma: "; afis(s_prim);
    produs(a_prim,b_prim,p_prim,p_ultim);
    g<<"produs: "; afis(p_prim);
    return 0;
}
**/

/** /// problema 29
struct nod{
    int val;
    nod *urm;
};
nod *prim, *ultim;
void adauga(int x){
    if(!prim){
        nod *p=new nod;
        p->val=x;
        p->urm=NULL;
        prim=p;
        ultim=p;
    }
    else{
        nod *p=new nod;
        p->val=x;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;
    }
}
void afis(nod *p){
    if(p==ultim) {g<<p->val<<" "; return ;}
    afis(p->urm);
    g<<p->val<<" ";
}
int main(){
    int x1,x2,x3;
    f>>x1>>x2;
    adauga(x1);
    adauga(x2);
    while(x2!=0){
        f>>x3;
        adauga(x3);
        if(x3==x1+x2) {ultim->urm=prim; break;}
        x1=x2;
        x2=x3;
    }
    afis(prim);
    return 0;
}
**/

 /// problema 30
struct nod{
    int lin, col, val;
    nod *urm;
};
nod *a_prim, *a_ultim, *b_prim, *b_ultim, *c_prim, *c_ultim;
int n,m;
void adauga(nod *&prim, nod *&ultim, int i, int j, int x){
    if(!prim){
        nod *p = new nod;
        p->lin=i;
        p->col=j;
        p->val=x;
        p->urm=NULL;
        prim=p;
        ultim=p;
    }
    else{
        nod *p = new nod;
        p->lin=i;
        p->col=j;
        p->val=x;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;
    }
}
void suma(nod *prim1, nod *prim2, nod *&prim3, nod *&ultim3){
    nod *p = prim1;
    nod *q = prim2;
    nod *t = 0;
    nod *w = 0;
    while(p&&q){
        if(q&&p->lin==q->lin&&p->col==q->col)
        {
            int s=p->val+q->val;
            adauga(prim3, ultim3, p->lin,p->col,s);
            p=p->urm;
            q=q->urm;
        }
        else
        if(q&&p->lin<q->lin||(p->lin==q->lin&&p->col<q->col))
        {
            adauga(prim3, ultim3, p->lin,p->col,p->val);
            p=p->urm;
        }
        else
        if(q&&p->lin>q->lin||(p->lin==q->lin&&p->col>q->col))
        {
            adauga(prim3, ultim3, q->lin,q->col,q->val);
            q=q->urm;
        }
    }
    while(p)
    {
        adauga(prim3, ultim3, p->lin,p->col,p->val);
        p=p->urm;
    }
    while(q)
    {
        adauga(prim3, ultim3, q->lin,q->col,q->val);
        q=q->urm;
    }
}
void afis(nod *prim, int i, int j){
    if(i==n+1) return;
    if(j==m+1) {g<<'\n'; return afis(prim,i+1,1);}
    if(!prim) {g<<0<<" "; return afis(prim,i,j+1);}
    if(prim->lin==i&&prim->col==j) {g<<prim->val<<" "; afis(prim->urm, i, j+1);}
    else {g<<'0'<<'\n'; afis(prim, i, j+1);}
}
    ///while(prim){
       /// g<<prim->lin<<" "<<prim->col<<" "<<prim->val<<'\n';
      ///  prim=prim->urm;
    ///}
}
int main(){
    int x;
    f>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        f>>x;
        if(x) adauga(a_prim,a_ultim,i,j,x);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        f>>x;
        if(x) adauga(b_prim,b_ultim,i,j,x);
    }
    suma(a_prim, b_prim, c_prim, c_ultim);
    afis(c_prim,1,1);
    return 0;
}

