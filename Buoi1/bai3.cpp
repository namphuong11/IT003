#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }


    sort(a, a + N);

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;


        if (binary_search(a, a + N, x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
