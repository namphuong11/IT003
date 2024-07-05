#include <bits/stdc++.h>
using namespace std;

#define NULLKEY StudentInfo()

struct StudentInfo {
    string name;
    string className;
    string school;

    StudentInfo() {
        name = "";
        className = "";
        school = "";
    }

    StudentInfo(const string& n, const string& c, const string& s) {
        name = n;
        className = c;
        school = s;
    }
};

StudentInfo bangbam[11];

int hambam(const string& className) {
    int sum = 0;
    for (char c : className) {
        sum += c;
    }
    return sum % 11;
}

void insert(const StudentInfo& student) {
    int i = hambam(student.className);
    if (bangbam[i].className.empty()) {
        bangbam[i] = student;
    } else {
        int z = 1;
        while (!bangbam[i].className.empty()) {
            i = i + z * z;
            z++;
            if (i >= 11) {
                i -= 11;
            }
        }
        bangbam[i] = student;
    }
}

void display() {
    printf("\nBANG BAM CUA BAN:\n");
    printf("\n\t\tVi tri\t\t\tHo va ten\t\tLop\t\tTruong\n");
    for (int i = 0; i < 11; i++) {
        if (!bangbam[i].className.empty()) {
            printf("\n\t\t%d\t\t\t%s\t\t%s\t\t%s", i, bangbam[i].name.c_str(), bangbam[i].className.c_str(), bangbam[i].school.c_str());
        } else {
            printf("\n\t\t%d\t\t\tNULL\t\tNULL\t\tNULL", i);
        }
    }
}

int main() {
    for (int i = 0; i < 11; i++) {
        bangbam[i] = NULLKEY;
    }

    insert(StudentInfo("John Doe", "Class A", "ABC School"));
    insert(StudentInfo("Jane Smith", "Class B", "XYZ School"));
    insert(StudentInfo("Alice Johnson", "Class A", "ABC School"));
    insert(StudentInfo("Bob Anderson", "Class C", "DEF School"));
    insert(StudentInfo("Charlie Brown", "Class B", "XYZ School"));
    insert(StudentInfo("David Lee", "Class D", "GHI School"));
    insert(StudentInfo("Emily Davis", "Class C", "DEF School"));

    display();

    return 0;
}
