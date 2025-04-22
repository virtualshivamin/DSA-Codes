/*
Leetcode Problem 
69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

*/


#include <iostream>
using namespace std;

int integerSqrt(int x) {
    int min = 0;
    int max = x;
    long mid;
    int ans = 0;
    while (min <= max) {
        mid = min + (max - min) / 2;
        if ((mid * mid) > x)
            max = mid - 1;
        else {
            ans = mid;
            min = mid + 1;
        }
    }
    return ans;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    int result = integerSqrt(x);
    cout << "The integer square root of " << x << " is " << result << endl;

    return 0;
}
