#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;

	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}

	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &A,double a,double b)
{
    DONTHUC *p = new DONTHUC(a,b);
    if (A.head == NULL)
    {
        A.head = new Node(p);
        A.tail = A.head;
    }
    else
    {
        A.tail ->next = new Node(p);
        A.tail = A.tail ->next;
    }
}

void Xuat(DATHUC &P) {
    if (P.head == nullptr) {
        cout << 0;
        return;
    }
    Node *current_node = P.head;
    bool first_donthuc = true;
    while (current_node != nullptr) {
        DONTHUC *current_donthuc = current_node->data;
        if (current_donthuc->heso == 0) {
            current_node = current_node->next;
            continue;
        }
        if (first_donthuc) {
            first_donthuc = false;
            if (current_donthuc->heso < 0) cout << "-";
            if (abs(current_donthuc->heso) != 1 || current_donthuc->somu == 0) cout << abs(current_donthuc->heso);
        }
        else {
            if (current_donthuc->heso > 0) cout << "+";
            else cout << "-";
            if (abs(current_donthuc->heso) != 1 || current_donthuc->somu == 0) cout << abs(current_donthuc->heso);
        }
        if (current_donthuc->somu != 0) {
            cout << "x";
            if (current_donthuc->somu != 1) {
                cout << "^" << current_donthuc->somu;
            }
        }
        current_node = current_node->next;
    }
    if (first_donthuc) cout << 0;
}

double TinhDaThuc(DATHUC& P, double x) {
    double result = 0;
    DONTHUC* dt = nullptr;
    for (Node* p = P.head; p != nullptr; p = p->next) {
        dt = p->data;
        result += dt->heso * pow(x,dt->somu);

    }
    return result;
}



int main() {
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }


    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
