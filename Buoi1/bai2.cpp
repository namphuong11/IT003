#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        cin.ignore();
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) {
            return a.x < b.x;
        } else {
            return a.y >b.y;

        }});
    for (int i = 0; i < n; i++)
    {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}
