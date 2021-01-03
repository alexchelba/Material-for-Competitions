#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{
    int val,niv;
    nod *st, *dr;
};
nod *rad;
/** /// problema 11
int n;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st = q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr = q;}
        }
    }
}
void repl(nod *&p, int x, int y){
    if(p){
        if(p->val==x) p->val=y;
        repl(p->st,x,y);
        repl(p->dr,x,y);
    }
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
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    int a,b;
    f>>a>>b;
    afis(rad); g<<'\n';
    repl(rad,a,b);
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 12
nod *rad2;
int n,m;
bool ok=true;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st = q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr = q;}
        }
    }
}
bool verif(nod *p, nod *q){
    if(n!=m) {ok=false; return false;}
    if(p&&q){
        if(p->val!=q->val) {ok=false; return false;}
        verif(p->st,q->st);
        verif(p->dr,q->dr);
    }
    else if((p&&!q)||(!p&&q)) {ok=false; return false;}
    return ok;
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
    f>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    for(int i=1;i<=m;i++){
        int x;
        f>>x;
        creare(x,rad2);
    }

    afis(rad); g<<'\n';
    afis(rad2); g<<'\n';
    g<<verif(rad,rad2);
    return 0;
}
**/

/** /// problema 13
/// ex. 7 4 2 0 0 3 0 0 4 2 0 0 3 0 0, true
int n,x;
bool ok=true;
nod* creare(){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->st = creare();
            p->dr = creare();
            return p;
        }
    }
    return NULL;
}
bool verif(nod *p, nod *q){
    if(p&&q){
        g<<p->val<<" "<<q->val<<" "<<ok<<'\n';
        if(p->val!=q->val) {ok=false; return false;}
        verif(p->st,q->st);
        verif(p->dr,q->dr);
    }
    else if((p&&!q)||(!p&&q)) {ok=false; return false;}
    return ok;
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
    rad = creare();
    if(rad->dr && rad->st){
        nod *q = rad->dr;
        nod *r = rad->st;
        g<<verif(q,r)<<'\n';
    }
    else if((!rad->st&&rad->dr)||(rad->st&&!rad->dr)) g<<0<<'\n';
    else g<<1<<'\n';
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 14
/// ex. 7 4 2 0 0 3 0 0 4 2 0 0 3 0 0, rez = 4
int n,x,nrs,nrd,ok;
nod* creare(){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->st = creare();
            p->dr = creare();
            return p;
        }
    }
    return NULL;
}
int par(nod *p, nod *q){
    if(p&&q){
        ///g<<p->val<<" "<<q->val<<" "<<ok<<'\n';
        if(p->val%2==0) nrs++;
        if(q->val%2==0) nrd++;
        par(p->st,q->st);
        par(p->dr,q->dr);
    }
    return nrs+nrd+ok;
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
    rad = creare();
    if(rad->val%2==0) ok=1;
    if(rad->dr && rad->st){
        nod *q = rad->dr;
        nod *r = rad->st;
        g<<par(q,r)<<'\n';
    }
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 15
int n,x,nrs,nrd,ok,viz[100];
nod* creare(int niv){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->niv = niv;
            p->st = creare(niv+1);
            p->dr = creare(niv+1);
            return p;
        }
    }
    return NULL;
}
void afis(nod *p){
    if(p){
        if(!viz[p->niv]) {g<<p->val<<" "; viz[p->niv]=1;}
        afis(p->st);
        afis(p->dr);
    }
}
int main()
{
    rad = creare(0);
    if(rad->val%2==0) ok=1;
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 16
int n,x,nrs,nrd;
nod* creare(){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->st = creare();
            p->dr = creare();
            return p;
        }
    }
    return NULL;
}
void afis(nod *p){
    if(p){
        g<<p->val<<" ";
        if(!nrs) {nrs=1; nrd=0; afis(p->st);}
        else
        if(!nrd) {nrd=1; nrs=0; afis(p->dr);}
    }
}
int main()
{
    rad = creare();
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 17
int n,x,nr;
nod* creare(){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->st = creare();
            p->dr = creare();
            return p;
        }
    }
    return NULL;
}
void afis(nod *p){
    if(p){
        afis(p->st);
        afis(p->dr);
        nr++;
        if(nr==n) {g<<p->val<<" "; return;}
    }
}
int main()
{
    f>>n;
    rad = creare();
    afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 18
/// ex. 7 4 2 0 0 5 0 0 9 7 0 0 9 0 0, true
int n,x,ok=1;
nod* creare(){
    if(f>>x){
        if(x){
            nod *p = new nod;
            p->val = x;
            p->st = creare();
            p->dr = creare();
            return p;
        }
    }
    return NULL;
}
int afis(nod *p){
    if(p){
        if(p->st) if(p->st->val>p->val||(p->st->val<rad->val&&p->val>rad->val)) {ok=0; return 0;}
            else afis(p->st);
        if(p->dr) if(p->dr->val<p->val||(p->dr->val>rad->val&&p->val<rad->val)) {ok=0; return 0;}
            else afis(p->dr);
    }
    return ok;
}
int main()
{
    rad = creare();
    g<<afis(rad); g<<'\n';
    return 0;
}
**/

/** /// problema 19
int n,maxx,minn=2000000000;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st = q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr = q;}
        }
    }
}
void afis(nod *p){
    if(p){
        g<<p->val<<" ";
        if(p->val>maxx) maxx=p->val;
        if(p->val<minn) minn=p->val;
        afis(p->st);
        afis(p->dr);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        x = rand()%n;
        if(cbrt(x)==(int)cbrt(x)) creare(x,rad);
        else creare(x*x*x,rad);
    }
    afis(rad);
    g<<'\n';
    g<<maxx<<" "<<minn<<'\n';
    return 0;
}
**/

/** /// problema 20
int n,a[100],k;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st = q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr = q;}
        }
    }
}
int afis(nod *p){
    if(p){
        afis(p->st);
        a[++k] = p->val;
        afis(p->dr);
    }
    return k;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    g<<afis(rad);
    for(int i=1;i<=n;i++)
        g<<a[i]<<" ";
    g<<'\n';
    return 0;
}
**/

 /// problema 21
int n,a[100],k;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st = q;}
        }
        else if(x>p->val){
            if(p->dr) creare(x,p->dr);
                else {p->dr = q;}
        }
        else g<<"deja inserat.\n";
    }
}
void afis(nod *p){
    if(p){
        g<<p->val<<" ";
        afis(p->st);
        afis(p->dr);
    }
}
void frun(nod *p){
    if(p){
        if(!p->st&&!p->dr) a[++k]=p->val*2;
        frun(p->st);
        frun(p->dr);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    afis(rad); g<<'\n';
    frun(rad);
    for(int i=1;i<=k;i++)
        creare(a[i]*2, rad);
    afis(rad);
    return 0;
}

