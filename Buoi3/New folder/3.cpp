#include <bits/stdc++.h>
using namespace std;

struct hanghoa
{
    string ten;
    double gia;
    long long soluongcon;
    struct hanghoa *next;
};

struct List
{
    hanghoa *head;
    hanghoa *tail;
};

List copyList(List originalList) {
    List newList;
    newList.head = newList.tail = NULL;
    for (hanghoa* p = originalList.head; p != NULL; p = p->next) {
        hanghoa* newNode = new hanghoa;
        newNode->ten = p->ten;
        newNode->gia = p->gia;
        newNode->soluongcon = p->soluongcon;
        newNode->next = NULL;
        if (newList.head == NULL) {
            newList.head = newList.tail = newNode;
        } else {
            newList.tail->next = newNode;
            newList.tail = newNode;
        }
    }
    return newList;
}

void createlist(List &l)
{
    l.head = l.tail = NULL;
}

void addhanghoa(List &l)
{
    hanghoa *p = new hanghoa;
    cout <<"hay nhap vao ten hang: ";
    cin >> p->ten;
    cout <<"hay nhap vao gia don le: ";
    cin >>p->gia;
    cout <<"hay nhap vao so luong con trong kho: ";
    cin >>p->soluongcon;
    p->next=NULL;
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }

}

void sapxepgia(hanghoa *head)
{
    hanghoa *p,*q,*min;
    for (p = head;p!=NULL;p=p->next)
    {
        for (q = p->next;q!=NULL;q=q->next)
        {
            min =p;
            if (min->gia>q->gia)
            {
                min = q;
            }
            else if (min->gia==q->gia)
            {
                if (min->ten>q->ten)
                {
                    min = q;
                }
            }
            if (min != p)
            {
                string ten = p->ten;
                p->ten = min ->ten;
                min ->ten = ten;
                int gia = p->gia;
                p->gia=min->gia;
                min->gia = gia;
                int soluong = p->soluongcon;
                p ->soluongcon = min ->soluongcon;
                min->soluongcon = soluong;
            }
        }
    }

}
void inDsMatHang(List l, int x, int y) {
    hanghoa* p = l.head;
    while (p != NULL) {
        if (p->soluongcon > x && p->soluongcon < y) {
            cout << "Tên hàng hóa: " << p->ten << endl;
            cout << "Giá đơn lẻ: " << p->gia << endl;
            cout << "Số lượng còn trong kho: " << p->soluongcon << endl << endl;
        }
        p = p->next;
    }
}


void print_list(List l)
{
    hanghoa *p = l.head;
    for (p;p!=NULL;p=p->next)
    {
        cout <<"ten cua hang hoa la: " <<p->ten <<endl;
        cout <<"gia cua mot " <<p->ten <<" la: " <<p->gia <<endl;
        cout <<"so luong " <<p->ten <<" con trong kho la: " <<p->soluongcon <<endl;
    }
}

int main()
{
    List l;
    createlist(l);
    int n;
    cout <<"so luong hang hoa can nhap thong tin la: ";
    cin >>n;
    for (int i =0 ;i<n;i++)
    {
        cout <<"Hay nhap thong tin cua hang hoa thu " <<i+1 <<endl;
        addhanghoa(l);
    }
    int x,y;
    cin >>x >>y;
    if (x>y) {cin >>x >>y;}
    inDsMatHang(l,x,y);


}
