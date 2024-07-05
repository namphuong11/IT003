#include <bits/stdc++.h>
using namespace std;

struct Node
{
    unsigned int data;
    struct Node *pnext;
};

struct List
{
    Node *phead;
    Node *ptail;
};

void createlist(List &l)
{
    l.phead = l.ptail = NULL;
}

void addnode(List &l, unsigned int x)
{
    Node *p = new Node;
    p -> data = x;
    p->pnext = NULL;
    if (l.phead == NULL)
    {
        l.phead = p;
        l.ptail = l.phead;
    }
    else
    {
        l.ptail -> pnext = p;
        l.ptail = p;
    }
}

void deletenode(List &l)
{
    unsigned int x;
    cin >>x;
    int check = 0;
    if (l.phead != NULL)
    {
        Node *p = l.phead;
        Node *q = p -> pnext;
        while (p != NULL)
        {
            if (q!=NULL && q->data == x)
            {
                p->pnext = q->pnext;
                delete q;
                if (p->pnext == NULL)
                {
                    l.ptail = p;
                }
                break;
            }
            if (q == NULL)
            {
                cout <<"ko co";
            }
            p = q;
            q = q->pnext;

        }
    }
}

void printlist(List &l)
{
    Node *p;
    p = l.phead;
    while (p!=NULL)
    {
        cout <<p ->data <<" ";
        p = p->pnext;
    }
}

void printlist1(List &l)
{
    vector <unsigned int> a;
    Node *p = l.phead;
    while (p != NULL)
    {
        a.push_back(p->data);
        p = p->pnext;
    }
    for (int i = a.size()-1;i>=0;i--)
    {
        cout <<a[i] <<" ";
    }
}

Node *find(List &l)
{
    unsigned int x;
    cin >>x;
    Node *p;
    p=l.phead;
    while (p!=NULL && p->data== x)
    {
        p = p->pnext;
    }
    return p;

}

void sortlist(List &l)
{
    Node *i,*j,*min;
    for (i = l.phead;i!=NULL;i=i->pnext)
    {
        min = i;
        for (j = i->pnext;j!=NULL;j=j->pnext)
        {
            if (min->data > j->data)
            {
                min = j;
            }
        }
        if (min!=i)
        {
            int data= i->data;
            i ->data = min ->data;
            min ->data = data;
        }

    }
}

void insertz(List &l)
{
    unsigned int x;
    cin >>x;
    Node *p = new Node;
    p ->data = x;
    p->pnext = NULL;
    Node *i = l.phead;
    if (l.phead == NULL || x<i->data)
    {
        p -> pnext = l.phead;
        l.phead = p;
    }
    else
    {
        while (i != NULL && x > i->pnext->data)
        {
            i = i->pnext;
        }
        p ->pnext = i ->pnext;
        i->pnext = p;

    }

}
int main()
{
    List l;
    createlist(l);
    int n;
    cin >>n;
    int x;
    for (int i = 0;i<n;i++)
    {
        cin >> x;
        addnode(l,x);

    }
    sortlist(l);
    printlist(l);



}
