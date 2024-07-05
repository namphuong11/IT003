#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    unsigned int num;
    stack<unsigned int> s;
    queue<unsigned int> z;

    cout << "Nhap vao mot so nguyen khong am: ";
    cin >> num;
    unsigned int num1 = num;

    int x = 1;
    while (num/x!=0)
    {
        x *= 10;
    }

    x/=10;

    while (num!=0)
    {
        int digit = num / x;
        s.push(digit);
        num -= (x*digit);
        x/=10;
    }

    while (num1!=0)
    {
        int digit = num1%10;
        z.push(digit);
        num1/=10;
    }
    cout <<"so dao nguoc bang stack la: ";
    while (!s.empty())
    {
        int digit = s.top();
        cout <<digit;
        s.pop();
    }

    cout <<endl <<"so dao nguoc bang queue la: ";
    while (!z.empty())
    {
        int digit = z.front();
        cout <<digit;
        z.pop();
    }

    return 0;
}

