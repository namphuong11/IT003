#include <bits/stdc++.h>
using namespace std;
#define MAX 5

struct Stack
{
    unsigned int a[MAX];
    int top;
};

void createstack(Stack &s)
{
    s.top = -1;
}

bool isempty(Stack &s)
{
    if (s.top == -1)
    {
        cout <<"Stack is empty" <<endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool isfull(Stack &s)
{
    if (s.top>=MAX-1)
    {
        cout <<"stack is full" <<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stack &s)
{
    unsigned int x;
    cin >>x;
    if (isfull(s))
    {
        return;
    }
    else
    {
        s.top++;
        s.a[s.top] = x;
    }
}

void pop(Stack &s)
{
    if (isempty(s))
    {
        return;
    }
    else
    {
        s.top--;
    }
}

void printstack(Stack &s)
{
    for (int i = s.top; i >= 0; i--)
    {
        cout << s.a[i] <<" ";

    }
    cout <<endl;
}
unsigned int top(Stack &s)
{
    return s.a[s.top];
}

int main()
{
    Stack s;
    createstack(s);
    isempty(s);
    for (int i = 0;i<MAX;i++)
    {
        push(s);
    }
    printstack(s);
    isfull(s);
    pop(s);
    printstack(s);
    cout <<top(s);


}
