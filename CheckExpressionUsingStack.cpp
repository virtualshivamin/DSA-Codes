/*

Check Expression is valid or not using Stack.

Notes: 

Stack application : 
1) Recursion 
2) Polish notation 
    - infix to postfix 
    - infix to prefix 
    - Evaluation of postfix expression 
3) Expression is valid or not 
    - a+b => ab+ 
    - a+b => +ab

*/

#include <iostream>
using namespace std;

#define max 5 

    int top=-1;
    char s[max];

    void push(int a){
        if (top>=max-1){
            cout<<"Stack Overflow";
        }
        else{
            s[top+1] = a;
            top++;
        }
    }
    
    void pop(){
        if (top<0){
            cout<<"Stack Underflow";
        }
        else{
            top--;
        }
    }
    
    void display()
    {
        if (top<0){
            cout << "Stack is empty."; 
        }
        else{
            cout << "Stack elements : " << endl; 
            for (int i = 0; i <= top ; i++)
            {
                cout << s[i] << endl;
            }
        }
        
    }


int main(){

    char arr[] = "{[(a*b)+(c/d)]*e}";

    for(int i = 0; i < sizeof(arr) ; i++)
    {
        if(arr[i] == '{' || arr[i] == '(' || arr[i] == '[' )
            push(arr[i]);
        else if ( arr[i] == '}' || arr[i] == ']' || arr[i] == ')' )
            pop();
        
        
            if (top == -1)
            cout << "Expression is right.";
        else
            cout << "Expression is wrong.";
    }
    if (top == -1)
            cout << "Expression is right.";
        else
            cout << "Expression is wrong.";

    return 0;

}