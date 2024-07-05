#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;

    // Tính số cây còn lại sau khi đốn hạ
    n -= ceil(n * 1.0 / (a * k - a * (k - 1) / 2 - b * m + b * (m - 1) / 2));

    // Tính số ngày cần để đốn hạ cây còn lại
    long long days = ceil(n * 1.0 / (a + b));
    cout << days;

    return 0;
}
