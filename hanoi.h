#include<stdio.h>
#include <stdlib.h>
#define MAX 200


typedef struct stack {
    int arr[MAX];
    int top;
}stack;
//   ******************* Stack funtions *******************

// Initiation of the stack 
stack init(stack st);

// Fill the stack with the disks
stack fillTower(int n, stack st);

// Check if the stack is empty
int emptyStack(stack st);

// Push a value onto the stack
stack push(stack st, int val);

// Pop a value from the stack
int pop(stack* st);

// Print the stack
void printStack(stack st);

void printTowers(stack source, stack aux, stack dest);
//   ******************* Hanoi funtions *******************

// Hanoi recursive function
void hanoiRec(int n, stack* source, stack* dest, stack* aux);

// Make legal move from source to destination tower
void makeLegalMove(stack* source, stack* dest, char s, char d);

// Hanoi iterative function
void hanoiIter(int n, stack* source, stack* dest, stack* aux);

