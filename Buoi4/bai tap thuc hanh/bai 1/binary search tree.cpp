#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *pleft;
    struct Node *pright;
};

typedef Node *Tree;

void createtree(Tree &s)
{
    s = NULL;
}

void LNR(Tree &s)
{
    if (s!=NULL)
    {
        LNR(s->pleft);
        cout <<s->data <<" ";
        LNR(s->pright);
    }

}

void LRN(Tree &s)
{
    if (s!=NULL)
    {
        LRN(s->pleft);
        LRN(s->pright);
        cout <<s->data <<" ";
    }
}

void NLR(Tree &s)
{
    if (s!=NULL)
    {
        cout <<s->data <<" ";
        NLR(s->pleft);
        NLR(s->pright);
    }
}

void NRL(Tree &s)
{
    if (s!=NULL)
    {
        cout <<s->data <<" ";
        NRL(s->pright);
        NRL(s->pleft);
    }
}

void RNL(Tree &s)
{
    if (s!=NULL)
    {
        RNL(s->pright);
        cout <<s->data <<" ";
        RNL(s->pleft);
    }
}

void RLN(Tree &s)
{
    if (s!=NULL)
    {
        RLN(s->pright);

        RLN(s->pleft);
        cout <<s->data <<" ";
    }
}

void addnode(Tree &s, int x) {
    if (s == NULL) {
        Node *p = new Node;
        p->data = x;
        p->pleft = p->pright = NULL;
        s = p;
    } else {
        if (s->data == x) return;
        else if (s->data > x) addnode(s->pleft, x);
        else addnode(s->pright, x);
    }
}


Node *findx(Tree &s, int x)
{
    if (s!=NULL)
    {
        if (s->data == x) return s;
        else if (s->data > x) return findx(s->pright,x);
        else return findx(s->pleft,x);
    }
    return NULL;
}

void thaythe(Tree &t, Tree &p)
{
    if (p->pleft != NULL)
    {
        thaythe(t,p->pleft);
    }
    else
    {
        t->data = p->data;
        t=p;
        p= p->pright;
    }
}
void deletenode(Tree &s,char x)
{
    if (s!=NULL)
    {
        if (s->data<x) deletenode(s->pright,x);
        else if (s->data>x) deletenode(s->pleft,x);
        else
        {
            Node *p;
            p = s;
            if (s->pright == NULL) s = s->pleft;
            else if (s->pleft==NULL) s = s->pright;
            else
            {
                thaythe(p,s->pright);
            }
            delete p;
        }
    }
    else cout<<"KO THAY" <<endl;
}
int dem1nut(Tree &s)
{
    if (s == nullptr)
    {
        return 0;
    }
    else
    {
        if ((s->pleft == nullptr && s->pright != nullptr) || (s->pright == nullptr && s->pleft != nullptr))
            return 1 + dem1nut(s->pleft) + dem1nut(s->pright);
        else
            return dem1nut(s->pleft) + dem1nut(s->pright);
    }
}

int demsonut(Tree &s)
{
    if (s!=NULL)
    {
        return 1 + demsonut(s->pleft) +demsonut(s->pright);
    }
    return 0;

}

int dem2con(Tree &s)
{
    if (s==NULL)
    {
        return 0;
    }
    else
    {
        if (s->pleft != NULL || s->pright != NULL )
    {
        return 1+ dem2con(s->pleft) + dem2con(s->pright);
    }
    else return dem2con(s->pleft) + dem2con(s->pright);
    }
}

int demnutla(Tree &root)
{
    if (root == NULL)
        return 0;
    else if (root->pleft == NULL && root->pright == NULL)
        return 1;
    else
        return demnutla(root->pleft) + demnutla(root->pright);
}

int tinhchieucao(Tree &s)
{
    if (s==NULL)
    {
        return -1;
    }
    else
    {
        int leftheight=tinhchieucao(s->pleft);
        int rightheight=tinhchieucao(s->pright);
        return max(leftheight,rightheight) +1;
    }
}


int main()
{
    Tree s;
    createtree(s);
    for (int i = 0;i<5;i++)
    {
        char x;
        cin >>x;
        addnode(s,x);
    }
    cout <<dem2con(s);
}



