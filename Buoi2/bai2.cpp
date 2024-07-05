#include <bits/stdc++.h>
using namespace std;
void sx(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        sx(arr, left, j);
    }
    if (i < right) {
        sx(arr, i, right);
    }
}
int main()
{
    int n;
    cin >>n;
    vector <int> a(n);
    for (int i = 0;i<n;i++)
    {
        cin >>a[i];
    }
    sx(a,0,n-1);
    a.erase(unique(begin(a), end(a)), end(a));
    cout <<a.size();


}
