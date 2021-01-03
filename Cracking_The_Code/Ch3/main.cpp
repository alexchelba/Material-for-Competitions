#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/**
class my_stack
{
private:
    struct node{
        int value;
        int minn;
        int counter;
        node *prev;
    };
    node *first, *last;
public:
    my_stack(){
        first = NULL;
        last = NULL;
    }
    void push(int x)
    {
        if(!first)
        {
            first = new node;
            first->value = x;
            first->minn = x;
            first->counter = 1;
            first->prev = NULL;
            last = first;
        }
        else
        {
            node *p = new node;
            p->value = x;
            p->prev = last;
            p->counter = last->counter + 1;
            p->minn = min(x, last->minn);
            last = p;
        }
    }
    int pop()
    {
        if(!last) return 0;
        node *p = last;
        int val = last->value;
        last = last->prev;
        delete p;
        return val;
    }
    int peek()
    {
        if(last)
            return last->value;
        return NULL;
    }
    int minn()
    {
        if(!last) return 0xFFFFFFF;
        return last->minn;
    }
    int size_of()
    {
        if(!last) return 0;
        return last->counter;
    }
};

class set_of_stacks
{
private:
    struct stacks
    {
        my_stack s;
        int no;
        stacks *next;
        stacks *prev;
    };
    stacks *first, *last;
    int threshold = 3;
public:
    set_of_stacks()
    {
        first = NULL;
        last = NULL;
    }
    set_of_stacks(int threshold)
    {
        this->threshold = threshold;
        first = NULL;
        last = NULL;
    }
    void push(int x)
    {
        if(!first)
        {
            first = new stacks;
            first->s.push(x);
            first->no = 1;
            first->next = NULL;
            first->prev = NULL;
            last = first;
        }
        else
        {
            if(last->s.size_of()<threshold)
                last->s.push(x);
            else
            {
                stacks *p = new stacks;
                p->s.push(x);
                p->no = last->no + 1;
                p->prev = last;
                p->next = NULL;
                last = p;
            }
        }
    }
    int pop()
    {
        if(!last) return 0;
        if(last->s.size_of()) return last->s.pop();
        else {
            if(last->prev)
            {
                stacks *p = last;
                last = last->prev;
                last->next = NULL;
                delete p;
                return last->s.pop();
            }
            else return 0;
        }
    }
    int peek()
    {
        if(last->s.size_of())
            return last->s.peek();
        else
        {
            if(last->prev)
            {
                stacks *p = last;
                last = last->prev;
                last->next = NULL;
                delete p;
                return last->s.peek();
            }
            else return 0;
        }
    }
    int popAt(int index)
    {
        if(!index) return 0;
        stacks *p = last;
        if(!p) return 0;
        while(p->no != index && p)
        {
            p = p->prev;
        }
        if(!p) return 0;

        return p->s.pop();
    }
    int size_of()
    {
        if(!last) return 0;
        if(last->s.size_of())
            return last->no;
        if(last->prev)
        {
            stacks *p = last;
            last = last->prev;
            last->next = NULL;
            delete p;
            return last->no;
        }
        return 0;
    }
};

int main()
{
    set_of_stacks s;
    int x;
    while(f>>x)
    {
        s.push(x);
    }
    int n = s.size_of();
    while(s.size_of())
    {
        if(s.size_of()==n)
            g<<s.popAt(s.size_of())<<" ";
        else
        {
            g<<'\n'<<s.popAt(s.size_of())<<" ";
            n=s.size_of();
        }
    }
    return 0;
}
**/

/** /// towers of Hanoi
int n;
stack<int> s1,s2,s3;
void move_disks(int k)
{
    //g<<k<<" "<<s1.top()<<'\n';
    if(s3.size()==n) return;
    else
    if(k==1)
    {
        if(!s1.size()) move_disks(k+1);
        else
        {
            int m = s1.top();
            if( (s2.size() && s2.top()>m) || !s2.size())
            {
                s2.push(m);
                s1.pop();
                move_disks(3);
            }
            else
            if( (s3.size() && s3.top()>m) || !s3.size())
            {
                s3.push(m);
                s1.pop();
                move_disks(2);
            }
            else move_disks(k+1);
        }
    }
    else
    if(k==2)
    {
        if(!s2.size()) move_disks(k+1);
        else
        {
            int m = s2.top();
            if( (s3.size() && s3.top()>m) || !s3.size())
            {
                s3.push(m);
                s2.pop();
                move_disks(1);
            }
            else
            if( (s1.size() && s1.top()>m) || !s1.size())
            {
                s1.push(m);
                s2.pop();
                move_disks(3);
            }
            else move_disks(k+1);
        }
    }
    else
    if(k==3)
    {
        if(!s3.size()) move_disks(1);
        else
        {
            int m = s3.top();
            if( (s1.size() && s1.top()>m) || !s1.size())
            {
                s1.push(m);
                s3.pop();
                move_disks(2);
            }
            else
            if( (s2.size() && s2.top()>m) || !s2.size())
            {
                s2.push(m);
                s3.pop();
                move_disks(1);
            }
            else move_disks(1);
        }
    }
}
int main()
{
    f>>n;
    for(int i=n;i>=1;i--)
        s1.push(i);
    move_disks(1);
    while(s3.size())
    {
        g<<s3.top()<<" ";
        s3.pop();
    }
    return 0;
}
**/

/**
class MyQueue
{
private:
    stack<int> s1, s2;
    void move_from_s1_to_s2()
    {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    void move_from_s2_to_s1()
    {
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
public:
    void push_in_queue(int x)
    {
        move_from_s2_to_s1();
        s2.push(x);
        move_from_s1_to_s2();
    }
    int pop_from_queue()
    {
        int y = s2.top();
        s2.pop();
        return y;
    }
    int front_of_queue()
    {
        return s2.top();
    }
    int size_of_queue()
    {
        return s2.size();
    }

};
int main()
{
    int n;
    MyQueue q;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        f>>x;
        q.push_in_queue(x);
    }
    q.push_in_queue(10);
    while(q.size_of_queue())
    {
        g<<q.front_of_queue()<<" ";
        q.pop_from_queue();
    }
    g<<'\n';
    return 0;
}
**/

/** /// sort a stack in ascending order
int n,x;
stack<int> s,r;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        s.push(x);
    }
    while(s.size())
    {
        int w = s.top();
        s.pop();
        if(!r.size()) r.push(w);
        else
        {
            while(r.size()&&r.top()<w)
            {
                s.push(r.top());
                r.pop();
            }
            r.push(w);
        }
    }
    while(r.size())
    {
        g<<r.top()<<'\n';
        r.pop();
    }
    return 0;
}
**/
