#include <bits/stdc++.h>
using namespace std;

struct NS
 {
 int maso;
 string hoten;
 int thamnien;
 float hesoluong ;
 float luongcoban ;
 struct NS *next;
 };


struct Delist
{
    NS *phead;
    NS *ptail;
} ;

void createlist(Delist &l)
{
    l.phead = l.ptail = NULL;
}

void addnv(Delist &l)
{
    NS *NewNode = new NS;
    cout <<"Hay nhap vao ma so cua nhan vien: ";
    cin >> NewNode -> maso;
    cin.ignore();
    cout <<"Hay nhap vao ho ten cua nhan vien: ";
    getline(cin,NewNode->hoten);
    cout <<"Hay nhap vao tham nien cua nhan vien: ";
    cin >>NewNode->thamnien;
    cout<<"Hay nhap vao he so luong cua nhan vien: ";
    cin >> NewNode->hesoluong;
    if (NewNode->hesoluong<2.34 || NewNode->hesoluong>8)
    {
        cout <<"Hay nhap lai he so luong cua nhan vien: ";
        cin >>NewNode ->hesoluong;
    }
    NewNode -> luongcoban = 1490000;
    NewNode->next = NULL;

    if (l.phead == NULL )
    {
        l.phead = NewNode;
        l.ptail = NewNode;
    }
    else
    {
        l.ptail-> next = NewNode;
        l.ptail = NewNode;
    }

}
void print_list(Delist &l)
{
    NS *p;
    p = l.phead;
    while (p != NULL)
    {
        cout <<"Ma so cua nhan vien " <<p->hoten <<" la: " <<p->maso <<endl;
        cout <<"Tham nien cua nhan vien " <<p->hoten <<" la: "<<p->thamnien <<endl;
        cout <<"He so luong cua nhan vien la: " <<p->hoten <<" la: "<<p->hesoluong <<endl;
        cout <<"Luong cua nhan vien la: " <<p->hoten <<" la: "<<fixed <<setprecision(2) <<p->hesoluong*p->luongcoban <<endl;
        p=p->next;
    }

}

void sapxepthamnien(struct NS *phead)
{
    struct NS *i, *j, *min;

    // Sắp xếp danh sách theo thâm niên công tác giảm dần
    for (i = phead; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (min->thamnien < j->thamnien) {
                min = j;
            }
        }
        if (min != i) {
            // Hoán đổi nút i và nút min
            int maso = i->maso;
            i->maso = min->maso;
            min->maso = maso;
            string hoten = i->hoten;
            i->hoten = min->hoten;
            min->hoten = hoten;
            int thamnien = i->thamnien;
            i->thamnien = min->thamnien;
            min->thamnien = thamnien;
            float hesoluong = i->hesoluong;
            i->hesoluong = min->hesoluong;
            min->hesoluong = hesoluong;
            float luongcoban = i->luongcoban;
            i->luongcoban = min->luongcoban;
            min->luongcoban = luongcoban;
        }
    }
}

int luongtb(Delist &l)
{
    NS *i = l.phead;
    int count = 0;
    double kq = 0;
    while (i!=NULL)
    {
        kq += i->hesoluong * i->luongcoban;
        count++;
        i = i->next;
    }
    if (count == 0) return 0;
    else return kq/count;

}

void nam_tham_nien(Delist &l)
{
    sapxepthamnien(l.phead);
    NS *p = l.phead;
    int count = 0;
    while (p != NULL)
    {
        cout <<"Ma so cua nhan vien " <<p->hoten <<" la: " <<p->maso <<endl;
        cout <<"Tham nien cua nhan vien " <<p->hoten <<" la: "<<p->thamnien <<endl;
        cout <<"He so luong cua nhan vien la: " <<p->hoten <<" la: "<<p->hesoluong <<endl;
        cout <<"Luong cua nhan vien la: " <<p->hoten <<" la: "<<fixed <<setprecision(2) <<p->hesoluong*p->luongcoban <<endl;
        p=p->next;
        count ++;
        if (count == 5)
        {
            break;
        }
    }
}
void sapxepluong(NS *head)
{
    NS *i,*p,*min;
    for (i = head ;i!=NULL;i=i->next)
    {
        for (p = i->next;p!=NULL;p=p->next)
        {
            min = i;
            if (min->hesoluong*min->luongcoban < p->hesoluong*p->luongcoban)
            {
                min = p;
            }
            if (min != i)
            {
            int maso = i->maso;
            i->maso = min->maso;
            min->maso = maso;
            string hoten = i->hoten;
            i->hoten = min->hoten;
            min->hoten = hoten;
            int thamnien = i->thamnien;
            i->thamnien = min->thamnien;
            min->thamnien = thamnien;
            float hesoluong = i->hesoluong;
            i->hesoluong = min->hesoluong;
            min->hesoluong = hesoluong;
            float luongcoban = i->luongcoban;
            i->luongcoban = min->luongcoban;
            min->luongcoban = luongcoban;
            }
        }
    }
}
void nam_luong_cao(Delist &l)
{
    sapxepluong(l.phead);
    NS *p = l.phead;
    int count = 0;
    while (p != NULL)
    {
        cout <<"Ma so cua nhan vien " <<p->hoten <<" la: " <<p->maso <<endl;
        cout <<"Tham nien cua nhan vien " <<p->hoten <<" la: "<<p->thamnien <<endl;
        cout <<"He so luong cua nhan vien la: " <<p->hoten <<" la: "<<p->hesoluong <<endl;
        cout <<"Luong cua nhan vien la: " <<p->hoten <<" la: "<<fixed <<setprecision(2) <<p->hesoluong*p->luongcoban <<endl;
        p=p->next;
        count ++;
        if (count == 5)
        {
            break;
        }
    }


}






int main()
{
    Delist l;
    createlist(l);
    int n;
    cout <<"Hay nhap vao so nhan vien: ";
    cin >>n;
    for (int i =0;i<n;i++)
    {
        cout <<"Hay nhap thong tin cua nhan vien thu " <<i+1 <<endl;
        addnv(l);
    }
    print_list(l);
    return 0;
}
