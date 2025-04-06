/*

Array swapping using Recursion

*/

#include <iostream>
using namespace std;

// Swap function 
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// function to reverse the array
void reverseArray(int a[], int i, int n) {
    // stop when index reaches the middle
    if (i >= n / 2)
        return;

    // Swap start and end terms
    swap(a[i], a[n - i - 1]);

    // next start and end call
    reverseArray(a, i + 1, n);
}

int main() {
    // Initialize array
    int a[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    reverseArray(a, 0, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
