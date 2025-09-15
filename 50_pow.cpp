/*

Leetcode question 
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

*/


#include <iostream>
using namespace std;

class Solution {
    public:
    
        double myPow(double x, int n) {

            long N = n; 
            // this will handle negative values (negative me upon me ho jata hai aur minus lagega N pe)
            if (N < 0) { 
                x = 1 / x;
                N = -N;
            }
            double result = 1.0;
            while (N > 0) {
                if (N % 2 == 1) {
                    result *= x;
                }
                x *= x;
                N /= 2;
            }
            return result;

            /*

            Upar wale code ka dry run for x=2 and n=10 

            x       n       result
            2       10      1
            4       5       1
            4       5       4
            16      2       4
            256     1       4
            256     1       1024
            65536   0       1024

            */

            /* This i done which shows "Time Limit Exceeded" error 

            double pow = 0; 
            for(int i = n; i>0;i++)
                pow += x*x;
            return pow;
            */
        }
};

int main() {
    Solution sol;

    double x = 2.0;
    int n = 10;
    double result = sol.myPow(x, n);
    cout << x << " raised to the power " << n << " is: " << result << endl;

    return 0;
}