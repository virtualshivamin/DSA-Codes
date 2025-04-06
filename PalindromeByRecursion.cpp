/*
Check Palindrome using Recursion. 
*/


#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int n) {
    // for mid term
    if (i >= n / 2)
        return true;

    // Return false if not matched
    if (s[i] != s[n - i - 1])
        return false;

    return isPalindrome(s, i + 1, n);
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();

    if (isPalindrome(s, 0, n))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
