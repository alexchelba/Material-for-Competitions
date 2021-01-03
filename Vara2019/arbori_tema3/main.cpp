#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/// problema 22
struct nod{
    int val;
    nod *st, *dr, *prev;
};
nod *rad;
int n,ok=1;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = NULL;
    q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st=q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr=q;}
        }
    }
}
void sterg(nod *&q){
    if(q->st) sterg(q->st);
    if(!q->dr) {delete q; q=0;}
    else{
        nod *f = q->dr;
        delete q;
        q=f;
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
    f>>n;
    for(int i=1;i<=n;i++){
        int x;
        f>>x;
        creare(x,rad);
    }
    afis(rad); g<<'\n';
    if(rad->dr) sterg(rad->dr);
    afis(rad);
    return 0;
}

/** /// problema 23
int s[100],d[100],n;
struct nod{
    int val;
    nod *st, *dr;
};
nod *rad;
void creare(int x, nod *&p){
    nod *q = new nod;
    q->val = x;
    q->st = NULL;
    q->dr = NULL;
    if(!p) p=q;
    else{
        if(x<p->val){
            if(p->st) creare(x,p->st);
                else {p->st=q;}
        }
        else{
            if(p->dr) creare(x,p->dr);
                else {p->dr=q;}
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
int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        f>>s[i];
    }
    for(int i=1;i<=n;i++){
        f>>d[i];
    }
    s[n+1]=d[n+1]=0;
    int i = distance(s, max_element(s+1, s+n+1));
    int j = distance(d, min_element(d+1, d+n+1));
    if(s[i]==d[j]){
        nod *p = new nod;
        p->val=s[i];
        p->st=p->dr=NULL;
        rad=p;
        while(i<=n){s[i]=s[i+1]; i++;}
        while(j<=n){d[j]=d[j+1]; j++;}
        n--;
        for(int k=1;k<=n;k++)
            creare(s[k], rad->st);
        for(int k=1;k<=n;k++)
            creare(d[k], rad->dr);
    }
    afis(rad);
    return 0;
}
**/

/** /// problema 24
struct nod{
    char val;
    int niv;
    nod *st, *dr, *prev;
};
nod *rad;
char s[100];
int nrd,ok;
void adaug(char x, int niv, nod *&p){
    if(!ok) return;
    nod *q = new nod;
    q->val=x;
    q->st=NULL;
    q->dr=NULL;
    q->prev=NULL;
    q->niv=niv;
    if(!p) {p=q; ok=0;}
    else{
        if(p->niv==niv-1&&p->val!='*'&&ok){
            if(!p->st) {q->prev=p; p->st=q; ok=0;}
            else if(!p->dr) {q->prev=p; p->dr=q; ok=0;}
        }
        else{
            adaug(x,niv,p->st);
            adaug(x,niv,p->dr);
        }
    }
}
void sterg(nod *&p){
    if(p){
        if(p->st) if(p->st->val=='*') p->st=NULL;
        if(p->dr) if(p->dr->val=='*') p->dr=NULL;
        sterg(p->st);
        sterg(p->dr);
    }
}
void afis(nod *p){
    if(p){
        afis(p->st);
        afis(p->dr);
        g<<p->val<<" ";
    }
}
int main(){
    f.get(s,100);
    g<<s<<'\n';
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(') nrd++;
        else if(s[i]==')') nrd--;
        else if((s[i]>='a'&&s[i]<='z')||s[i]=='*') {ok=1; adaug(s[i],nrd,rad);}
    }
    sterg(rad);
    if(rad) afis(rad);
    return 0;
}
**/

/** /// problema 25 ????????????????????????????????????????????????????????????????????
struct nod{
    int val;
    nod *st, *dr;
};
nod *rad;
int n,pre[100],ino[100];
int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>pre[i];
    }
    for(int i=1;i<=n;i++){
        f>>ino[i];
    }
    int x = distance(ino, find(ino+1, ino+n+1, pre[1]));
    int nrarbst=x-1;
    int nrarbdr=n-x;
    nod *p=new nod;
    p->val=pre[1];
    p->st=p->dr=NULL;
    rad=p;
    for(int i=2;i<=1+nrarbst;i++)
        adaug(rad->st,pre[i]);
    return 0;
}
**/

/** /// stergerea unui nod cu val k
void cmmd(nod *&p, nod *&s){
    if(s->dr) cmmd(p,s->dr);
    p->val=s->val;
    nod *man = s;
    s = s->st;
    delete man;
}
void stergere(nod *&q, int k){
    if(!q) g<<"val negasita\n";
    if(q->val<k) stergere(q->dr,k);
    if(q->val>k) stergere(q->st,k);
    if(q->val==k){
        if(!q->st&&!q->dr){
            delete q;
            q=NULL;
        }
        else
        if(q->st&&!q->dr){
            nod *f = q->st;
            delete q;
            q=f;
        }
        else
        if(!q->st&&q->dr){
            nod *f = q->dr;
            delete q;
            q=f;
        }
        else{
            cmmd(q,q->st);
        }
    }
}
**/
