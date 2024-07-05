#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y, z;
};

int compare(Point& p1, Point& p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    if (p1.y != p2.y) {
        return p1.y > p2.y;
    }
    return p1.z < p2.z;
}

int partition(vector<Point>& points, int left, int right) {
    Point pivot = points[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (compare(points[j], pivot)) {
            i++;
            swap(points[i], points[j]);
        }
    }
    swap(points[i + 1], points[right]);
    return i + 1;
}

void ss(vector<Point>& points, int left, int right) {
    if (left < right) {
        int pivot_index = partition(points, left, right);
        ss(points, left, pivot_index - 1);
        ss(points, pivot_index + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    ss(points, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
        cout <<endl;
    }
    return 0;
}
