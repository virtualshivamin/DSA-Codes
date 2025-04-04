/*

Stack basics push, pop and display operation.

*/

#include <iostream>
using namespace std;

#define max 5 

    int top=-1;
    int s[max];

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
            cout << "Stack : ";
            for (int i = 0; i <= top ; i++)
            {
                cout << s[i] << endl;
            }
        }
        
    }


int main(){

    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();

    return 0;

}