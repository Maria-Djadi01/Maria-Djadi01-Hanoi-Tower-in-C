#include<stdio.h>
#include <stdlib.h>
#include "hanoi.h"



int main() {

    stack source, dest, aux;
    source = init(source);
    dest = init(dest);
    aux = init(aux);
    source = init(source);
    source = fillTower(5, source);
    printf("Source tower \n");
    printStack(source);
    printf("\n");

    hanoiRec(5, &source, &dest, &aux);
    printf("Destination tower \n");
    printStack(dest);
}

void hanoiRec(int n, stack* source, stack* dest, stack* aux) {
    if(n == 1) {
        int x = pop(&(*source));
        *dest = push(*dest, x);
        return;
    }
    else {
        hanoiRec(n-1, source, aux, dest);
        int x = pop(&(*source));
        *dest = push(*dest, x);
        hanoiRec(n-1, aux, dest, source);
    }
}

stack fillTower(int n, stack st) {
    for(int i = n; i > 0; i--) {
        st = push(st, i);
    }
    return st;
}


stack init(stack st) {
    st.top = -1;
    return st;
}

int emptyStack(stack st) {
    if(st.top <= 0) return 1;
    else return 0;
}

int fullStack(stack st) {
    if(st.top == MAX) return 1;
    else return 0;
}

stack push(stack st, int val) {
    st.top++;
    st.arr[st.top] = val;
    return st;
}

int pop(stack* st) {
    int val = st->arr[st->top];
    st->top--;
    return val;
}

void printStack(stack st) {
    if(emptyStack(st)) printf("The stack is empty \n");
    for(int i = 0; i <= st.top; i++) {
        printf("%d  ", st.arr[i]);
    }
}