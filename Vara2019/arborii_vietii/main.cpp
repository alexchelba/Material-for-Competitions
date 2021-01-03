#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/// forma poloneza
/** /// good job
struct nod{
    char op;
    nod *as, *ad;
};
char e[30],efp[30],a;
int pfp[30],p[30],n;
nod *c;
nod *arb(int li, int ls){
    nod *d;
    //int i,j,minn;
    int minn=pfp[ls];
    int i=ls;
    for(int j=ls;j>=li;j--)
        if(pfp[j]<minn){
            minn=pfp[j];
            i=j;
        }
    d=new nod;
    d->op=efp[i];
    if(li==ls) d->as=d->ad=0;
    else{
        d->as=arb(li,i-1);
        d->ad=arb(i+1,ls);
    }
    return d;
}
void parc(nod *d){
    if(d){
        parc(d->as);
        parc(d->ad);
        g<<d->op;
    }
}
int main()
{
    int j=0;
    f>>a;
    n=0;
    while(a!='.'){
        e[++n]=a;
        f>>a;
    }
    for(int i=1;i<=n;i++)
        switch(e[i]){
            case ')': j-=10; break;
            case '(': j+=10; break;
            case '+': p[i]=j+1; break;
            case '-': p[i]=j+1; break;
            case '*': p[i]=j+10; break;
            case '/': p[i]=j+10; break;
            default: p[i]=1000;
        }
    j=0;
    for(int i=1;i<=n;i++)
        if(e[i]!=')'&&e[i]!='('){
            j++;
            efp[j]=e[i];
            pfp[j]=p[i];
            //j++;
        }
    c=arb(1,j);
    parc(c);
    return 0;
}
**/

/** /// varianta de la Stefan

struct Nod
{
    char op;
    Nod *as, *ad;
};

char e[30],efp[30],a;
int pfp[30],p[30],i,j,n;

Nod *c;

Nod* arb(int li, int ls, char efp[30], int pfp[30])
{
    int i,j,min1;
    min1 = pfp[ls];
    i = ls;
    for(j = ls; j >= li; j--)
    {
        if(pfp[j] < min1)
        {
            min1 = pfp[j];
            i = j;
        }
    }
    Nod *c = new Nod;
    c->op = efp[i];
    if(ls == li) c->as=c->ad= 0;
    else
    {
        c->as = arb(li, i-1,efp, pfp);
        c->ad = arb(i+1, ls , efp, pfp);
    }
    return c;
}

void parc(Nod *c)
{
    if(c)
    {
        parc(c -> as);
        parc(c -> ad);
        g<<c->op;
    }
}

int vals[100];

int calc(Nod *c)
{
    switch(c -> op)
    {
        case '+': return (calc(c->as) + calc(c -> ad));
        case '-': return (calc(c->as) - calc(c -> ad));
        case '*': return (calc(c->as) * calc(c -> ad));
        case '/': return (calc(c->as) / calc(c -> ad));
        default : return vals[c->op - 'a'];
    }
}

int main()
{
    j = 0; f>>a; n = 1;
    while(a != '.')
    {
        e[n++]=a;
        f>>a;
    }
    n--;
    for(int i = 1; i <= n; i++)
        switch(e[i])
        {
            case ')': j -= 10;          break;
            case '(': j += 10;          break;
            case '+': p[i] = j + 1;     break;
            case '-': p[i] = j + 1;     break;
            case '*': p[i] = j + 10;    break;
            case '/': p[i] = j + 10;    break;
            default: p[i] = 1000;       break;
        }
    j = 1;
    for(int i = 1; i <= n; i++)
        if(e[i] != ')' && e[i] != '(')
        {
            efp[j] = e[i];
            pfp[j] = p[i];
            j++;
        }
    c = arb(1, j-1, efp, pfp);
    parc(c);

    g<<endl<<endl;
    int nV = 0; f>>nV;
    for(int i = 0; i < nV; i++) f >> vals[i];

    g<<endl<<calc(c);
    return 0;
}
**/

/// min-heap
struct nod{
    int val;
    nod *st, *dr, *prev;
};
nod *rad;
void creare(int x, nod *&p){
    nod *b=new nod;
    b->val=x;
    b->st=b->dr=NULL;
    b->prev=NULL;
    if(!p){

        p=b;
    }
    else{
        if(x<p->val){
            if(p->st) creare(x, p->st);
                else {b->prev = p; p->st=b;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {b->prev = p; p->dr=b;}
        }
    }
}
nod *indvalmin(nod* arb){
    if(arb->dr)
        if(arb->st>arb->dr) return arb->dr;
    return arb->st;
}
void combinare(nod* &arb){
    if(arb->st){
        nod *c = indvalmin(arb);
        if(arb->val>c->val){
            swap(arb->val,c->val);
            combinare(c);
        }
    }
}
void minheap(nod *&arb){
    if(arb->st) minheap(arb->st);
    combinare(arb);
    /**for(int i=n/2;i>=1;i--)
        combinare(i,n);**/
}
void heapsort(nod *&arb){
    //minheap(rad);
    if(arb->dr){
        heapsort(arb->dr);
    }
    else if(arb->st) heapsort(arb->st);
    swap(arb->val,rad->val);
    combinare(arb);
}
void afis(nod *rad){
    if(rad){
        g<<rad->val<<" ";
        afis(rad->st);
        afis(rad->dr);
    }
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    afis(rad);
    g<<'\n';
    ///combinare(rad);
    minheap(rad);
    afis(rad);
    g<<'\n';
    heapsort(rad);
    afis(rad);
    return 0;
}


/** /// min-heap
int arb[30001],n;
int indvalmin(int i, int n){
    if(2*i+1<=n)
        if(arb[2*i]>arb[2*i+1]) return 2*i+1;
    return 2*i;
}
void combinare(int i, int n){
    if(i<=n/2){
        int ind = indvalmin(i,n);
        if(arb[i]>arb[ind]){
            swap(arb[i],arb[ind]);
            combinare(ind,n);
        }
    }
}
void minheap(){
    for(int i=n/2;i>=1;i--)
        combinare(i,n);
}
void heapsort(){
    minheap();
    for(int i=n;i>=1;i--){
        swap(arb[i],arb[1]);
        combinare(1,i-1);
    }
}
void afis(){
    for(int i=1;i<=n;i++)
        g<<arb[i]<<" ";
    g<<'\n';
}
int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>arb[i];
    }
    ///afis(rad);
    minheap();
    afis();
    heapsort();
    afis();
    return 0;
}
**/
