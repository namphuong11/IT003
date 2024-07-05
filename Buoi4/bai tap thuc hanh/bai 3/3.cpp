#include <iostream>
using namespace std;

struct Tnode {
    int key;
    struct Tnode* left;
    struct Tnode* right;
};

typedef struct Tnode treeNode;

void createtree(treeNode*& s) {
    s = NULL;
}

void addnode(treeNode*& s, int x) {
    if (s == NULL) {
        treeNode* p = new treeNode;
        p->key = x;
        p->left = p->right = nullptr;
        s = p;
    }
    else {
        if (s->key == x)
            return;
        else if (s->key < x)
            addnode(s->right, x);
        else
            addnode(s->left, x);
    }
}

int countLeaft(treeNode* Root, int k) {
    if (Root == NULL)
        return 0;
    else if (Root->left == NULL && Root->right == NULL) {
        if (Root->key == k)
            return 1;
        else
            return 0;
    }
    else {
        int left = countLeaft(Root->left, k);
        int right = countLeaft(Root->right, k);
        return left + right;
    }
}

int OddSum(treeNode* Root) {
    if (Root == NULL)
        return 0;
    else {
        int sum = 0;
        if (Root->key % 2 != 0)
            sum += Root->key;
        sum += OddSum(Root->left);
        sum += OddSum(Root->right);
        return sum;
    }
}

int Sum(treeNode* Root) {
    if (Root!=NULL)
    {
        int left = Sum(Root->left);
        int right = Sum(Root->right);
        return left + right + Root->key;
    }
    return 0;
}

int EvenLeaf(treeNode* Root) {
    if (Root == NULL)
        return 0;
    else if (Root->left == NULL && Root->right == NULL) {
        if (Root->key % 2 == 0)
            return 1;
        else
            return 0;
    }
    else {
        int left = EvenLeaf(Root->left);
        int right = EvenLeaf(Root->right);
        return left + right;
    }
}

int countNodes(treeNode* Root, int k) {
    if (Root == NULL)
        return 0;
    else {
        int count = 0;
        if (Root->key > k)
            count = 1;
        count += countNodes(Root->left, k);
        count += countNodes(Root->right, k);
        return count;
    }
}

int main() {
    treeNode* s;
    createtree(s);
    for (int i = 0; i < 12; i++) {
        int x;
        cin >> x;
        addnode(s, x);
    }
    cout << "Gia tri nut la can dem: " << endl;
    int k;
    cin >> k;
    cout << "So luong la cua cay: " << countLeaft(s, k) << endl;
    cout << "Tong cac so le cua cay: " << OddSum(s) << endl;
    cout << "Tong cua ca cay: " << Sum(s) << endl;
    cout << "So luong nut la la so chan: " << EvenLeaf(s) << endl;
    cout << "Nhap so can biet co bao nhieu so lon hon: ";
    int z;
    cin >> z;
    cout << "So nut lon hon la: " << countNodes(s, z) << endl;
}
