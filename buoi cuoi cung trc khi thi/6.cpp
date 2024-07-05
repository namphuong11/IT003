#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

const int TABLE_SIZE = 10;
Node* table[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = nullptr;

    if (table[index] == nullptr)
        table[index] = newNode;
    else {
        Node* current = table[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
}

bool search(int key) {
    int index = hashFunction(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key)
            return true;
        current = current->next;
    }
    return false;
}

void remove(int key) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
                delete current;
            } else {
                prev->next = current->next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Bucket " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;

    insert(10);
    insert(21);
    insert(32);
    insert(14);
    insert(5);
    insert(144);
    insert(35);

    display();

    int key = 21;
    if (search(key))
        cout << "Key " << key << " found!" << endl;
    else
        cout << "Key " << key << " not found!" << endl;

    remove(key);

    display();

    return 0;
}
