#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

int i,j;
struct Stack{
       int items[MAX_SIZE];
       int top;
       };
       
void createStack(struct Stack *stack){
     stack->top = -1;
     }
     
bool isFull(struct Stack *stack){
     return stack-> top == MAX_SIZE -1;
     }

bool isEmpty(struct Stack *stack){
     return stack-> top == -1;
     }
     
void push(struct Stack *stack, int value){
     if(isFull(stack)){
                       printf("stack overflow can not push element\n", value);
                       } else {
                              stack->items[++stack->top] = value;
                              printf("pushed %d onto the stack.\n", value);
                              }
                       }
                       
void pop(struct Stack *stack, int value){
     if(isEmpty(stack)){
                       printf("stack underflow can not push element\n", value);
                       } else {
                              stack->items[++stack->top--];
                              printf("pushed %d onto the stack.\n", value);
                              }
                       }
                       