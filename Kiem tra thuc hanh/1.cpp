#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a, b;


    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    vector<size_t> positions;

    size_t found = a.find(b);
    while (found != string::npos) {
        positions.push_back(found);
        found = a.find(b, found + b.length());
    }


    if (positions.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (size_t pos : positions) {
            cout << pos+1 << endl;
        }
    }

    return 0;
}
