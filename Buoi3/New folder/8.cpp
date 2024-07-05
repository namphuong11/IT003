#include <bits/stdc++.h>
using namespace std;

void tobinary(int n)
{
    stack <int> s;
    while (n!=0)
    {
        int number = n% 2;
        n/=2;
        s.push(number);
    }
    while (!s.empty())
        {
            cout <<s.top();
            s.pop();
        }
}

void tooctal(int n)
{
    stack <int> s;
    while (n!=0)
    {
        int number = n% 8;
        n/=8;
        s.push(number);
    }
    while (!s.empty())
        {
            cout <<s.top();
            s.pop();
        }
}

void tohex(int n)
{
    stack <int> s;
    string digit = "0123456789ABCDEF";
    string result;
    while (n!=0)
    {
        int number = n% 16;
        n/=16;
        s.push(number);
    }
    while(!s.empty())
    {
        cout <<digit[s.top()];
        s.pop();
    }

}
int main()
{
    int number;
    cin >>number;
    cout<<"Nhi phan: ";
    tobinary(number);
    cout <<endl <<"Bat phan: ";
    tooctal(number);
    cout <<endl <<"Thap luc phan: ";
    tohex(number);
    return 0;
}
