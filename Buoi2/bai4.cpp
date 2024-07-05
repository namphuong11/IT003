#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge_sort(int a[],int b[],int c[],int n,int m)
{
    int i = 0,j=0,z=0;
    while (i <n && j<m)
    {

            if (a[i]<=b[i])
            {
                c[z++]= a[i++];
            }
            else
            {
             c[z++]=b[j++];
            }


        {
            c[z++] = a[i++];
        }
        if (j<m)
        {
            c[z++] = b[j++];
        }
    }
    for (int z = 0;z<n+m;z++)
    {
        cout <<c[z] <<" ";
    }

}
int main()
{
    int n,m;
    cin >>n >>m;
    int a[n],b[m];
    int c[n+m];
    for (int i =0;i<n;i++)
    {
        cin >>a[i];
    }
    for (int j = 0;j<m;j++)
    {
        cin >>b[j];
    }
    for (int z=0;z<n+m;z++)
    {
        c[z]=0;
    }
    merge_sort(a,b,c,n,m);

}
