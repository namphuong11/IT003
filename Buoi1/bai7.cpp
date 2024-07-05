#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int main()
{
    float a[100][100];
    int n,m;
    float sum = 0;
    cin >>n >>m;
    for (int i = 0 ; i<n;i++)
    {
        for (int j = 0 ;j<m;j++)
        {
            cin >>a[i][j];
        }
    }
    for (int i = 0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if  (i==j)
            {
                sum += a[i][j];
            }
        }
    }
    cout <<sum;
    return 0;


}
