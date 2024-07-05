#include <iostream>
#include <stack>

void moveDisk(std::stack<int>& source, std::stack<int>& destination) {
    int disk = source.top();
    source.pop();
    destination.push(disk);
}

void hanoi(int n, std::stack<int>& source, std::stack<int>& auxiliary, std::stack<int>& destination) {
    if (n > 0) {

        hanoi(n - 1, source, destination, auxiliary);


        moveDisk(source, destination);


        hanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    int n = 3;
    std::stack<int> source, auxiliary, destination;


    for (int i = n; i > 0; --i) {
        source.push(i);
    }

    hanoi(n, source, auxiliary, destination);

    return 0;
}
