#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    string name;
    float gpa;
    struct Node *pleft;
    struct Node *pright;
};

typedef Node *Tree;

void createtree(Tree &s)
{
    s = NULL;
}

void addnode (Tree&s,int id,string name,float gpa)
{
    Node *p = new Node;
    p ->id = id;
    p->name=name;
    p->gpa=gpa;
    p->pleft=nullptr;
    p->pright=nullptr;
    if (s==NULL)
    {
        s = p;
    }
    else
    {
        if (s->id == id)
        {
            cout <<"Sinh vien da ton tai" <<endl;
            return;
        }
        else if (s->id>id)
        {
            addnode(s->pleft,id,name,gpa);
        }
        else
        {
            addnode(s->pright,id,name,gpa);
        }
    }
}
void addnode1(Tree &s, int id, string name, float gpa)
{
    Node *p = new Node;
    p->id = id;
    p->name = name;
    p->gpa = gpa;
    p->pleft = nullptr;
    p->pright = nullptr;

    if (s == nullptr)
    {
        s = p;
    }
    else
    {
        if (s->gpa == gpa)
        {
            if (s->id > id)
            {
                addnode1(s->pleft, id, name, gpa);
            }
            else
            {
                addnode1(s->pright, id, name, gpa);
            }
        }
        else if (s->gpa > gpa)
        {
            addnode1(s->pleft, id, name, gpa);
        }
        else
        {
            addnode1(s->pright, id, name, gpa);
        }
    }
}

bool findX(Tree &s,int id)
{
        if (s != nullptr) {
            if (s->id == id) {
                return true;
            } else if (s->id > id) {
                findX(s->pleft,id);
            } else {
                findX(s->pright,id);
            }
        }

}

void thaythe(Tree &t, Tree &p)
{
    if (p->pleft != NULL)
    {
        thaythe(t,p->pleft);
    }
    else
    {
        t->name = p->name;
        t->id = p->id;
        t->gpa = p->gpa;
        t=p;
        p= p->pright;
    }
}
void deletenode(Tree &s,int x)
{
    if (s!=NULL)
    {
        if (s->gpa<x) deletenode(s->pright,x);
        else if (s->gpa>x) deletenode(s->pleft,x);
        else
        {
            deletenode(s->pleft, x);
            deletenode(s->pright, x);
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
}




void RNL(Tree &s)
{
    if (s!=NULL)
    {
        RNL(s->pright);
        cout << "MSSV cua sinh vien nay la: " << s->id << ", ten cua sinh vien la: " << s->name << ", diem trung binh cua sinh vien la: " << s->gpa << endl;
        RNL(s->pleft);
    }
}

int height(Tree &s)
{
    if (s==NULL)
    {
        return 0;
    }
    int right = height(s->pleft);
    int left = height(s->pright);
    return 1 + max(right,left);
}

void output()
{
    Tree sapxeptheodtb;
    createtree(sapxeptheodtb);
    Tree s;
    createtree(s);
    int choice;
    do
    {
        cout << "|------------------------------------------------------|" << endl;
        cout << "|                                                      |" << endl;
        cout << "|         1.Them sv vao cay                            |" << endl;
        cout << "|         2.Tim sv                                     |" << endl;
        cout << "|         3.Xoa cac sv co dtb 5.0                      |" << endl;
        cout << "|         4.Hien thi cac sv theo dtb giam dan          |" << endl;
        cout << "|         5.Hien thi chieu cao cua cay                 |" << endl;
        cout << "|         0.Thoat                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|------------------------------------------------------|" << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> choice;


        switch(choice)
        {
        case 1:
            {int id;
            string name;
            float gpa;
            cout << "Nhap ma sinh vien: ";
            cin >> id;
            cout << "Nhap ho ten sinh vien: ";
            cin.ignore();
            getline(cin, name);
            cout << "Nhap diem trung binh hoc tap: ";
            cin >> gpa;
            if (gpa<0 || gpa>10)
            {
                cout <<"Hay nhap lai diem trung binh hoc tap: ";
                cin >>gpa;
            }

            addnode(s,id,name,gpa);
            addnode1(sapxeptheodtb,id,name,gpa);
            cout <<"Sinh vien da duoc them vao thanh cong!";
            break;}
        case 2:
            {
                int id;
                cout <<"Hay nhap vao mssv cua sinh vien can tim: ";
                cin >>id;
                if (!findX(s, id)) {
                cout << "Khong tim thay sinh vien" << endl;
    }
    else
    {
        cout <<"Tim thay sinh vien" <<endl;
    }
            break;}
        case 3:
            {
                int a = 5;


            deletenode(sapxeptheodtb,a);
            cout <<"Da xoa cac sinh vien co diem trung binh 5.0" <<endl;
            break;}
        case 4:
            {RNL(sapxeptheodtb);
            break;}
        case 5:
            {cout <<"Chieu cao cua cay la: " <<height(sapxeptheodtb) <<endl;
            break;}
        case 0:
            {cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;}
        default:
            {cout <<"Lua chon cua ban khong hop le. Vui long nhap lai!" <<endl;
            break;

        }}
        cout <<endl;
    } while (choice != 0);
}

int main()
{
    output();
    return 0;
}

