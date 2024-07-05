#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
    int n,m;
    cin >>n >>m;

    list<int> a;
    unordered_map<int, list<int>::iterator> idx_map;

    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        idx_map[i] = prev(a.end());
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >>x;

        auto it = idx_map[x];

        a.erase(it);
        a.push_front(x);

        idx_map[x] = a.begin();

        cout << a.back() << " ";
    }

    return 0;
}
