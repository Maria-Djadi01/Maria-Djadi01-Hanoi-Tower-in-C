#include<stdio.h>
#include <stdlib.h>
#define MAX 200


typedef struct stack {
    int arr[MAX];
    int top;
}stack;

stack init(stack st);
void hanoiRec(int n, stack* source, stack* dest, stack* aux);
stack fillTower(int n, stack st);
int emptyStack(stack st);
stack push(stack st, int val);
int pop(stack* st);
void printStack(stack st);

