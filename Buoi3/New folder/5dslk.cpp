#include <bits/stdc++.h>
using namespace std;

struct Node
{
    unsigned int data;
    struct Node *pnext;
};

struct Stack
{
    struct Node *phead;
};

void createstack(Stack &l)
{
    l.phead = NULL;
}

bool isempty(Stack &l)
{
    if (l.phead == NULL)
    {
        cout <<"Stack is empty" <<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stack &l)
{
    unsigned int x;
    cin >>x;
    Node *p = new Node;
    p ->data = x;
    p->pnext = NULL;
    if (l.phead == NULL)
    {
        l.phead = p;
    }
    else
    {
        p->pnext=l.phead;
        l.phead = p;
    }

}

void pop(Stack &l)
{
    Node *p = l.phead;
    if (!isempty(l))
    {
        l.phead = p->pnext;
        delete p;
    }

}

Node *istop(Stack &l)
{
    return l.phead;
}

void printstack(Stack &l)
{
    Node *p = l.phead;
    while (p!=NULL)
    {
        cout <<p->data << " ";
        p = p->pnext;
    }
}

int main()
{
    Stack l;
    createstack(l);
    isempty(l);
    for (int i = 0;i<5;i++)
    {
        push(l);
    }
    printstack(l);
    pop(l);
    cout <<endl;
    printstack(l);
    cout <<istop(l);

}




