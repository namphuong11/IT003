#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string hoten;
    long long cmnd;
    string diachi;
    int soluongmua;
    struct Node *pnext;
    struct Node *prev;
};

struct List
{
    struct Node* phead;
    struct Node* ptail;
};

void createlist(List &l)
{
    l.phead = l.ptail = NULL;
}

void themngmua(List &l)
{
    Node *p = new Node;
    p->pnext = NULL;
    cin.ignore();
    cout <<"hay nhap vao ho ten cua nguoi mua: ";
    getline(cin,p->hoten);
    cout<<"nhap vao so cmnd cua nguoi mua: ";
    cin >>p->cmnd;
    Node *q = l.phead;
    cin.ignore();
    cout <<"hay nhap vao dia chi cua nguoi mua: ";
    getline(cin,p->diachi);
    cout <<"hay nhap vao so ve nguoi nay mua: ";
    cin>>p->soluongmua;
    if (p->soluongmua >2)
    {
        cout <<"khong the mua hon 2 ve, vui long nhap lai so ve mua: ";
        cin >>p->soluongmua;
    }
    if (l.phead == NULL)
    {
        l.phead = p;
        l.ptail = l.phead;
    }
    else
    {
        l.ptail ->pnext=p;
        l.ptail = p;
    }

    while (q!=NULL)
    {
        if (q->cmnd == p->cmnd)
        {
            cout <<"Nguoi nay da mua roi khong the mua them";
            l.ptail = l.ptail ->prev;
            l.ptail ->prev->pnext = NULL;
            delete p;
            break;
            q = q->pnext;
        }
    }

}

void printlist(List &l)
{
    Node *p = l.phead;
    for (p;p!=NULL;p=p->pnext)
    {
        cout <<"ten cua khach hang la: " <<p->hoten <<endl;
        cout <<"so cmnd cua khach hang la: " <<p->cmnd <<endl;
        cout <<"dia chi cua khach hang la: " <<p->diachi <<endl;
        cout <<"so luong mua cua khach hang la: " <<p->soluongmua <<endl;


    }
}

int main()
{
    List l;
    createlist(l);
    int n;
    cout <<"so luong nguoi mua la: ";
    cin >>n;
    for (int i = 0;i<n;i++)
    {
        themngmua(l);
    }
    printlist(l);
}
