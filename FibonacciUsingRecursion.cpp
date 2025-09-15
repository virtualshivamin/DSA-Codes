/*
This is a program for fibonacci series. 
This program is an example for multiple Recursion Calls, like at same time last and slast variable is calling 2 different fibonacci function recursively. 
*/

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int last = fibonacci(n - 1);
    int slast = fibonacci(n - 2);

    return last + slast;
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n-1) << endl;

    return 0;
}
