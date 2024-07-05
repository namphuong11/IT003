#include <bits/stdc++.h>
using namespace std;

void selection(int a[],int n)
{
    int min;
    for (int i =0;i<n;i++)
    {
        min = i;
        for (int j = i+1;j<n;j++)
        {
            if (a[j]<a[min])
            {
                min = j;
            }
        }
        swap(a[i],a[min]);
    }

}

void insert1(int a[],int n)
{
    for (int i = 1;i<n;i++)
    {
        int x=a[i], pos= i-1;
        while ((pos >=0) && (a[pos]>x))
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;

    }
}

void display(int a[],int n)
{
    for (int i = 0;i<n;i++)
    {
        cout <<a[i] <<" ";
    }
}

void counting(int a[],int n)
{
    int max = a[0];
    int min = a[0];
    for (int i = 1;i<n;i++)
    {
        if (a[i]>max)
        {
          max =  a[i];
        }
        if (a[i]<min)
        {
            min = a[i];
        }
    }
    int b[max-min+1] = {0},c[n];
    for (int i = 0;i<n;i++)
    {
        b[a[i]-min]++;
    }
    for (int i = 1;i<max-min+1;i++)
    {
        b[i] += b[i-1];
    }
    for (int i = 0;i<n;i++)
    {
        c[--b[a[i]-min]]=a[i];
    }
    for (int i = 0;i<n;i++)
    {
        a[i] = c[i];
    }

}

void radix(int a[],int &n)
{
    int max = a[0];
    int c[1000];
    for (int i = 0;i<n;i++)
    {
        if (max <a[i])
        {
            max = a[i];
        }
    }
    int x = 1;
    while (max/x>0)
    {
        int b[10] = {0};
        for (int i = 0;i<n;i++)
        {
            b[a[i]/x%10]++;
        }
        for (int i = 1;i<10;i++)
        {
            b[i] += b[i-1];
        }
        for (int i = n-1;i>=0;i--)
        {
            c[--b[a[i]/x%10]]=a[i];
        }
        for (int i = 0;i<n;i++)
        {
            a[i] = c[i];
        }
        x *= 10;

    }
}

void quick(int a[],int l,int r)
{
    int mid = (l + r)/2;
    int left = l,right = r;
    while (left <= right)
    {
        while (a[left] < a[mid])
        {
            left++;
        }
        while (a[right] > a[mid])
        {
            right--;
        }
        if (right >= left)
        {
            swap(a[right],a[left]);
            right--,left++;
        }
    }
    if (right > l)
    {
        quick(a,l,right);
    }
    if (left < r )
    {
        quick(a,left,r);
    }


}

void merge(int a[],int left,int mid,int right)
{
    int n1 = mid - left +1;
    int n2 = right - mid;
    int *p1 = new int [n1];
    int *p2 = new int [n2];
    for (int i = 0;i<n1;i++)
    {
        p1[i] = a[left+i];
    }
    for (int i = 0;i<n2;i++)
    {
        p2[i]= a[i+mid+1];
    }
    int i = 0,j=0,crt=left;
    while (i<n1 && j<n2 )
    {
        if (p1[i] <= p2[j])
        {
            a[crt++] = p1[i++];
        }
        else
        {
            a[crt++] = p2[j++];
        }}

        while (i<n1)
        {
            a[crt++] = p1[i++];
        }
        while (j<n2)
        {
            a[crt++] = p2[j++];
        }
    delete []p1,p2;
}
void mergeSort(int a[],int left,int right)
{
    if (left <right)
    {
        int mid = (left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);

        merge(a,left,mid,right);
    }
}
void mergesort(int a[],int n)
{
    mergeSort(a,0,n-1);
}

void interchangesort(int a[],int n)
{
    for (int i = 0;i<n;i++)
    {
        for (int j = i+1;j<n;j++)
        {
            if (a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

void bubblesort(int a[],int n)
{
    for (int i = 0;i<n;i++)
    {
        for (int j = n-1;j>i;j--)
        {
            if (a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}



int main()
{
    int a[100],n;
    cin >>n;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    counting(a,n);
    display(a,n);
    return 0;
}
