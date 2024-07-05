#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *pnext;
};

struct Queue
{
    struct Node *phead;
    struct Node *ptail;
};

void createqueue(Queue &s)
{
    s.phead = s.ptail = NULL;
}

bool isempty(Queue &s)
{
    if (s.phead == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue &s)
{
    int x;
    cin >>x;
    Node *p = new Node;
    p ->data = x;
    p->pnext=NULL;
    if (isempty(s))
    {
        s.phead = p;
        s.ptail = p;
    }
    else
    {
        s.ptail ->pnext = p;
        s.ptail = p;
    }
}

void dequeue(Queue &s)
{
    Node *p = s.phead;
    if (isempty(s))
    {
        cout <<"Queue is empty, can't remove any value" <<endl;
        return;
    }
    else
    {
        s.phead = p->pnext;
        delete p;
    }
}

int front(Queue &s)
{
    return s.phead->data;
}

void display(Queue &s)
{
    Node *p = s.phead;
    while (p!= NULL)
    {
        cout <<p->data <<" ";
        p = p->pnext;
    }
    cout <<endl;
}

int main()
{
    Queue s;
    createqueue(s);
    if (isempty(s))
    {
        cout <<"Queue is empty" <<endl;
    }
    for (int i = 0;i<5;i++)
    {
        enqueue(s);
    }
    display(s);
    dequeue(s);
    display(s);
    cout <<front(s);


}
