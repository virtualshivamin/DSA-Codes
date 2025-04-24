/*

DSA class
Evaluate postfix Expression using stack 

623+-382/+*2^3+

*/


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else s.push(a / b);
            } else {
                s.push(stoi(token)); 
                // Note : stoi is a function in C++ that converts String to integer directly
            }
        }
        return s.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};  
    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}
