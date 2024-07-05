#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >>n >> m;
    stack <int> a;
    for (int i = 0;i<n;i++)
    {
        a.push(i+1);
    }
    for (int i = 0;i<m;i++)
    {
        int called;
        cin >>called;
        if (called = a.top())
        {
            a.pop();
            a.push(called);
        }
        cout <<a.top() <<" ";


    }
}
