#include <bits/stdc++.h>
using namespace std;
struct nod{
    int val;
    nod *urm;
};
nod *stiva, *coada_inc, *coada_sf;
int n,a[101];
void push_stiva(int x)
{
    if(!stiva){
        stiva = new nod;
        stiva->val = x;
        stiva->urm = NULL;
    }
    else{
        nod *aux;
        aux = new nod;
        aux->val = x;
        aux->urm = stiva;
        stiva = aux;
    }
}
void pop_stiva()
{
    nod *c;
    if(stiva){
        c = stiva;
        stiva = stiva->urm;
        delete c;
    }
    else cout<<"N-avem ce sterge...";
}
void afis_stiva()
{
    nod *c = stiva;
    while(c){
        cout<<c->val<<" ";
        c = c->urm;
    }
    cout<<'\n';
}
void modif_stiva(int ord, int x, int val_dorita){
    nod *c = stiva;
    nod *v;
    int nr=0;
    while(c && nr<ord){
        if(c->val==x) nr++;
        if(nr==ord)
            {
                v=c;
                break;
            }
        c = c->urm;
    }
    if(c) c->val = val_dorita;
    else{
        int nr1=0;
        c=stiva;
        while(nr1!=nr&&c){
            if(c->val==x) nr1++;
            if(nr1==nr) c->val = val_dorita;
            c=c->urm;
        }
    }
}
void push_coada(int x){
    if(!coada_inc){
        coada_inc = new nod;
        coada_inc->val = x;
        coada_inc->urm = NULL;
        coada_sf = coada_inc;
    }
    else{
        nod *aux;
        aux = new nod;
        aux->val = x;
        aux->urm = NULL;
        coada_sf->urm = aux;
        coada_sf = aux;
    }
}
void pop_coada(){
    nod *c;
    if(coada_inc)
    {
        c = coada_inc;
        coada_inc = coada_inc->urm;
        delete c;
    }
}
void afis_coada(){
    nod *c = coada_inc;
    while(c){
        cout<<c->val<<" ";
        c = c->urm;
    }
    cout<<'\n';
}
void modif_coada(int ord, int x, int val_dorita){
    nod *c = coada_inc;
    nod *v;
    int nr=0;
    while(c && nr<ord){
        if(c->val==x) nr++;
        if(nr==ord)
            {
                v=c;
                break;
            }
        c = c->urm;
    }
    if(c) c->val = val_dorita;
    else{
        int nr1=0;
        c=coada_inc;
        while(nr1!=nr&&c){
            if(c->val==x) nr1++;
            if(nr1==nr) c->val = val_dorita;
            c=c->urm;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        push_stiva(a[i]);
        push_coada(a[i]);
    }
    int val_inlocuitoare, val_inlocuita, ord_aparitiei;
    cin>>ord_aparitiei;
    cin>>val_inlocuita;
    cin>>val_inlocuitoare;
    /** /// secventa pt stiva
    afis_stiva();
    pop_stiva();
    afis_stiva();
    modif_stiva(ord_aparitiei, val_inlocuita, val_inlocuitoare);
    afis_stiva();
    **/
    /// secventa pt coada
    afis_coada();
    pop_coada();
    afis_coada();
    modif_coada(ord_aparitiei, val_inlocuita, val_inlocuitoare);
    afis_coada();
    return 0;
}
