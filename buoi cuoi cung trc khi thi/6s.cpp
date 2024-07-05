#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string className;
    string schoolName;
    Student* next;
};

const int TABLE_SIZE = 10;
Student* table[TABLE_SIZE];

int hashFunction(string key) {
    int sum = 0;
    for (char c : key)
        sum += c;
    return sum % TABLE_SIZE;
}

void insert(string name, string className, string schoolName) {
    int index = hashFunction(className);
    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->className = className;
    newStudent->schoolName = schoolName;
    newStudent->next = nullptr;

    if (table[index] == nullptr)
        table[index] = newStudent;
    else {
        Student* current = table[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = newStudent;
    }
}

bool search(string className) {
    int index = hashFunction(className);
    Student* current = table[index];
    while (current != nullptr) {
        if (current->className == className)
            return true;
        current = current->next;
    }
    return false;
}

void remove(string className) {
    int index = hashFunction(className);
    Student* current = table[index];
    Student* prev = nullptr;
    while (current != nullptr) {
        if (current->className == className) {
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
        Student* current = table[i];
        while (current != nullptr) {
            cout << current->name << " (" << current->className << ", " << current->schoolName << ") ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;

    insert("John Smith", "12A", "ABC High School");
    insert("Jane Doe", "11B", "XYZ High School");
    insert("David Johnson", "12A", "ABC High School");
    insert("Emily Davis", "10C", "DEF High School");
    insert("Michael Brown", "11B", "XYZ High School");

    display();

    string className = "12A";
    if (search(className))
        cout << "Students in class " << className << " found!" << endl;
    else
        cout << "Students in class " << className << " not found!" << endl;

    remove(className);

    display();

    return 0;
}
