/*
Key value ke pehle tak ascending aur uske baad descending 
*/



#include <iostream>
using namespace std;

int main() {
    int key, temp = 0, n;
    cout << "Input size: ";
    cin >> n;
    int a[n];

    cout << "Input array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Input key : ";
    cin >> key;

    // Sort left part 0 to key in ascending order
    for (int i = 0; i <= key; i++) {
        bool didswap = false;
        for (int j = 0; j < key - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                didswap = true;
            }
        }
        if (!didswap) break;
    }

    // Sort right part key+1 to n-1 in descending order
    for (int i = 0; i < n - key - 2; i++) {
        bool didswap = false;
        for (int j = key + 1; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
                didswap = true;
            }
        }
        if (!didswap) break;
    }

    cout << "Modified array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
