#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/**
/// main problem : given a binary tree, check if it is balanced
struct node
{
    int val;
    node *left, *right;
};
node *root;
void insert_in_tree(int x)
{
    if(!root)
    {
        root = new node;
        root->val = x;
        root->left = NULL;
        root->right = NULL;
    }
    else
    if(!root->left)
    {
        node *o = new node;
        o->val = x;
        o->left = NULL;
        o->right = NULL;
        root->left = o;
    }
    else
    if(!root->right)
    {
        node *o = new node;
        o->val = x;
        o->left = NULL;
        o->right = NULL;
        root->right = o;
    }
    else
    {
        node *q = root;
        node *p = root;
        int ok=0;
        while(q->left && p->right && !ok)
        {
            p = p->right;
            q = q->left;
            if(!q->right)
            {
                node *o = new node;
                o->val = x;
                o->left = NULL;
                o->right = NULL;
                q->right = o;
                ok=1;
                break;
            }
            else
            if(!p->left)
            {
                node *o = new node;
                o->val = x;
                o->left = NULL;
                o->right = NULL;
                p->left = o;
                ok=1;
                break;
            }
        }
        if(!ok)
        {
            if(!q->left)
            {
                node *o = new node;
                o->val = x;
                o->left = NULL;
                o->right = NULL;
                q->left = o;
            }
            else
            if(!p->right)
            {
                node *o = new node;
                o->val = x;
                o->left = NULL;
                o->right = NULL;
                p->right = o;
            }
        }
    }
}
void output_tree(node *p)
{
    if(p)
    {
        output_tree(p->left);
        g<<p->val<<" ";
        output_tree(p->right);
    }
}
int maxDepth(node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    return 1 + max(maxDepth(p->left), maxDepth(p->right));
}
int minDepth(node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    return 1 + min(minDepth(p->left), minDepth(p->right));
}
bool is_balanced_tree(node *p)
{
    if(maxDepth(p)-minDepth(p)>1)
        return false;
    return true;
}
int main()
{
    int n;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        f>>x;
        insert_in_tree(x);
    }
    g<<is_balanced_tree(root)<<'\n';
    output_tree(root);
    return 0;
}
**/

/**
/// main problem : given a directed graph and 2 nodes - a,b , find if there is a route between a and b
vector<int> v[1001];
int m,n,a,b,viz[1001];
bool dfs(int k, int p)
{
    viz[k]=1;
    if(k==p) return true;
    for(int i=0;i<v[k].size();i++)
    {
        if(!viz[v[k][i]])
        {
            return dfs(v[k][i], p);
        }
    }
    return false;
}
int main()
{
    f>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        f>>x>>y;
        v[x].push_back(y);
    }
    f>>a>>b;
    if(dfs(a,b)) g<<"it exists\n";
    else
    {
        memset(viz,0,sizeof(viz));
        if(dfs(b,a)) g<<"it exists\n";
        else g<<"it doesn't exist\n";
    }
    return 0;
}
**/

/**
/// main problem : given an array in ascending order, create a binary tree of minimal height with its elements
struct node
{
    int val;
    node *left, *right;
};
node *root;
int a[1001], n;
node* create_tree(int start, int endof)
{
    if(start>endof) return NULL;
    int mid = (start+endof)/2;
    node *p = new node;
    p->val = a[mid];
    p->left = create_tree(start,mid-1);
    p->right = create_tree(mid+1, endof);
    return p;
}
void output_tree(node *p)
{
    if(p)
    {
        output_tree(p->left);
        g<<p->val<<" ";
        output_tree(p->right);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i];
    root = create_tree(1,n);
    output_tree(root);
    return 0;
}
**/

/**
/// given a binary search tree, create, for each, level in tree, a list with all nodes on it.
struct node
{
    int val;
    node *left, *right;
};
node *root;
struct list_level
{
    int val;
    list_level *next, *prev;
};
int a[1001], n, max_lvl;
list_level *lists[1001];
node* create_tree(int start, int endof)
{
    if(start>endof) return NULL;
    int mid = (start+endof)/2;
    node *p = new node;
    p->val = a[mid];
    p->left = create_tree(start,mid-1);
    p->right = create_tree(mid+1, endof);
    return p;
}
void output_tree(node *p)
{
    if(p)
    {
        output_tree(p->left);
        g<<p->val<<" ";
        output_tree(p->right);
    }
}
void create_lists(node *p, int k)
{
    if(p)
    {
        list_level *q = new list_level;
        q->val = p->val;
        q->prev = NULL;
        q->next = NULL;
        if(!lists[k])
        {
            lists[k]=q;
            max_lvl = max(max_lvl, k);
        }
        else
        {
            list_level *t = lists[k];
            while(t->next)
                t = t->next;
            q->prev = t;
            t->next = q;
        }
        create_lists(p->left, k+1);
        create_lists(p->right, k+1);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i];
    root = create_tree(1,n);
    output_tree(root);
    g<<'\n';
    create_lists(root, 0);
    for(int i=0;i<=max_lvl;i++)
    {
        list_level *p = lists[i];
        g<<"level "<<i<<": ";
        while(p)
        {
            g<<p->val<<" ";
            p = p->next;
        }
        g<<'\n';
    }
    return 0;
}
**/

/// find successor of a node in a BST (for in-order traversal)
struct node
{
    int val;
    node *prev, *left, *right;
};
node *root;
int a[1001], n;
node* create_tree(int start, int endof)
{
    if(start>endof) return NULL;
    int mid = (start+endof)/2;
    node *p = new node;
    p->prev = NULL;
    p->val = a[mid];
    p->left = create_tree(start,mid-1);
    if(p->left) p->left->prev = p;
    p->right = create_tree(mid+1, endof);
    if(p->right) p->right->prev = p;
    return p;
}
void output_tree(node *p)
{
    if(p)
    {
        output_tree(p->left);
        g<<p->val<<" ";
        output_tree(p->right);
    }
}
node* successor(node *p)
{
    if(p->right) return p->right;
    node *q = p->prev;
    if(q->left == p) return q;
    while(q && q->val<p->val) q = q->prev;
    return q;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>a[i];
    root = create_tree(1,n);
    output_tree(root);
    g<<'\n';
    node *p = successor(root->left->right->right);
    g<<p->val<<'\n';
    return 0;
}

/// 4.6, 4.7, 4.8 are yet to be done
