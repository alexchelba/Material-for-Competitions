#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct node {
    int val;
    node *next;
};
int x;
void add_to_SLL(node *&first, node *&last, int x)
{
    if(!first){
        first = new node;
        first->val = x;
        first->next = NULL;
        last = first;
    }
    else {
        node *p = new node;
        p->val = x;
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
node* delete_node_from_SLL(node *&first, node *p){
    if(p == first){
        first = first->next;
        delete p;
        return first;
    }
    node *ant = first;
    while(ant->next != p){
        ant = ant->next;
    }
    ant->next = p->next;
    delete p;
    return ant->next;
}
void write_SLL(node *first){
    node *p = first;
    while(p){
        g<<p->val<<" ";
        p = p->next;
    }
    g<<'\n';
}

/** /// simple singly linked list
int main()
{
    node *first=NULL, *last=NULL;
    while(f>>x){
        add_to_SLL(first, last, x);
    }
    write_SLL(first);
    return 0;
}
**/

/** /// 2.1 Write code to remove duplicates from an unsorted linked list without a temporary buffer.
int main()
{
    node *first = NULL, *last = NULL;
    while(f>>x){
        add_to_SLL(first, last, x);
    }
    node *p0 = first;
    while(p0) {
        node *p = first;
        while(p!=p0){
            if(p->val == p0->val) p = delete_node_from_SLL(first, p);
            else p = p->next;
        }
        p0 = p0->next;
    }
    node *p = first;
    write_SLL(first);
    return 0;
}
**/

/** /// 2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
void delete_special_from_middle_SLL(node *p) {
    node *q = p->next;
    p->val = q->val;
    p->next = q->next;
    delete q;
}
int main(){
    node *first=NULL, *last=NULL;
    int n=0;
    while(f>>x){
        n++;
        add_to_SLL(first, last, x);
    }
    write_SLL(first);

    int m=1;
    node *p = first;
    while(p&&m<(n+1)/2){
        m++;
        p=p->next;
    }
    delete_special_from_middle_SLL(p);
    write_SLL(first);
    return 0;
}
**/

/** /// 2.4
/// You have two numbers represented by a linked list, where each node contains a single digit.
/// The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
/// Write a function that adds the two numbers and returns the sum as a linked list.
node *add_SLLs(node *first1, node *first2){
    int t=0;
    node *last3;

    node *first3 = new node;
    first3->val = first1->val + first2->val;
    t = first3->val / 10;
    first3->val = first3->val%10;
    first3->next = NULL;
    last3 = first3;

    node *p1 = first1->next;
    node *p2 = first2->next;
    while(p1 && p2) {
        node *p = new node;
        p->val = p1->val + p2->val + t;
        t = p->val/10;
        p->val = p->val%10;
        p->next = NULL;
        last3->next = p;
        last3 = p;

        p1 = p1->next;
        p2 = p2->next;
    }
    return first3;
}
int main()
{
    int n,m;
    f>>n>>m;
    node *first1=NULL, *last1=NULL;
    while(n){
        int x = n%10;
        n = n/10;
        add_to_SLL(first1, last1, x);
    }
    write_SLL(first1);

    node *first2=NULL, *last2=NULL;
    while(m){
        int x = m%10;
        m = m/10;
        add_to_SLL(first2, last2, x);
    }
    write_SLL(first2);

    node *first3 = add_SLLs(first1, first2);
    write_SLL(first3);
    return 0;
}
**/

/// 2.5
/// Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
node *circular_start(node *first){
    node *p1 = first;
    node *p2 = first;
    while(p2->next){
        p1=p1->next;
        p2=p2->next->next;
        if(p1==p2) break;
    }
    if(p2->next==NULL) return NULL;
    p1 = first;
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}
int main()
{
    node *first=NULL, *last=NULL;
    while(f>>x){
        add_to_SLL(first, last, x);
    }
    node *p = first;
    while(p){
        if(p->val == last->val) {last->next = p; break;}
        p=p->next;
    }
    if(last->next==NULL) g<<0<<'\n';
    else {
        node *circ = delete_node_from_SLL(first, last);
        g<<circ->val<<'\n';
        node *circ2 = circular_start(first);
        g<<circ2->val<<" ";
    }
    ///write_SLL(first);
    return 0;
}
