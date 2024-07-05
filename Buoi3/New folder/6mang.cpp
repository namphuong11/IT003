#include <bits/stdc++.h>
using namespace std;
#define MAX 5

struct Queue
{
    int a[MAX];
    int f,r;
};

void createqueue(Queue &s)
{
    s.f = s.r = -1;
}

bool isempty(Queue &s)
{
    if (s.f == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isfull(Queue &s)
{
    if (s.r>=MAX-1)
    {
        cout <<"queue is full" <<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue &s)
{
    int x;
    cin >>x;
    if (isfull(s))
    {
        cout <<"queue is full" <<endl;
        return;
    }
    else
    {
        s.a[++s.r] = x;
        if (s.f == -1)
        {
            s.f = 0;
        }
    }
}

void dequeue(Queue &s)
{
    if (isempty(s))
    {
        cout <<"Queue is empty, can't remove" <<endl;
        return;
    }
    else
    {
        s.f++;
    }
}

int front(Queue &s)
{
    if (isempty(s)) {
            cout << "Queue is empty. No element to peek.\n";
            return -1;
        }
    return s.a[s.f];
}

void display(Queue &s)
{
    if (isempty(s)) {
            cout << "Queue is empty. No element to display.\n";
            return;
        }

    else
    {
        for (int i = s.f;i<=s.r;i++)
        {
            cout <<s.a[i] <<" ";
        }
        cout <<endl;
    }
}

int main()
{
    Queue s;
    createqueue(s);
    if (isempty(s))
    {
        cout <<"Queue is empty" <<endl;
    }
    for (int i = 0;i<6;i++)
    {
        enqueue(s);
    }
    display(s);
    dequeue(s);
    display(s);
    cout <<front(s);


}
