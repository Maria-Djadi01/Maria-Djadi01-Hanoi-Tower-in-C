#include<stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include <math.h>



int main() {
    int n = 3;

    stack source, dest, aux;
    // initiation of the towers
    source = init(source);
    dest = init(dest);
    aux = init(aux);
    source = init(source);

    // fill the source tower
    source = fillTower(n, source);


    printf("Source tower \n");
    printStack(source);
    printf("\n");

    // hanoi function
    hanoiIter(n, &source, &dest, &aux);
    
    printf("\n\nDestination tower \n");
    printStack(dest);
}

void hanoiRec(int n, stack* source, stack* dest, stack* aux) {
    if(n == 1) {
        // Move the last disk from source to destination tower
        int x = pop(source);
        *dest = push(*dest, x);
    }
    else {
        // Move (n-1) disk from source to auxilary tower
        hanoiRec(n-1, source, aux, dest);
        int x = pop(source);
        *dest = push(*dest, x);
        // Move (n-1) disk from auxilary to destination tower
        hanoiRec(n-1, aux, dest, source);
    }
}


void hanoiIter(int n, stack* source, stack* dest, stack* aux) {
    int nbMoves = pow(2, n) - 1;
    // Temporary stack
    stack *temp;

    // If the number of disks is even, then we interchange between aux and dest
    if(n % 2 == 0) {
        *temp = *dest;
        *dest = *aux;
        *aux = *temp;
    }

    for(int i = 1; i <= nbMoves; i++) {
        // Legal movement between source and destination
        if(i % 3 == 1) makeLegalMove(source, dest, 'S', 'D');
        // Legal movement between source and auxiliary
        if(i % 3 == 2) makeLegalMove(source, aux, 'S', 'A');
        // Legal movement between auxilary and destination
        if(i % 3 == 0) makeLegalMove(aux, dest, 'A', 'D');

        printf("\n-------------i = %d------------", i);
        printf("\nSource \n");
        printStack(*source);
        printf("\nAux \n");
        printStack(*aux);
        printf("\nDest \n");
        printStack(*dest);
    }
}

void makeLegalMove(stack* source, stack* dest, char s, char d) {
    // The top disks of source and destination towers
    int srcTopDisk, dstTopDisk;

    //  If source tower is empty, then we move the top disk of destination to source
    if(emptyStack(*source)) {
        dstTopDisk = pop(dest);
        *source = push(*source, dstTopDisk);
        // printf("Move disk %d from %c to %c\n",dstTopDisk, d, s);
    }

    //  If dest tower is empty, then we move the top disk of source to dest
    else if(emptyStack(*dest)) {
        srcTopDisk = pop(source);
        *dest = push(*dest, srcTopDisk);
        // printf("Move disk %d from %c to %c\n",srcTopDisk, s, d);
    }

    //  else if the two towers are not empty
    else {
        // pop the two top disks of their towers
        srcTopDisk = pop(source);
        dstTopDisk = pop(dest);

        // if source top disk is bigger than dest top disk then push it back 
        // then the dest top disk above
        if(srcTopDisk > dstTopDisk) {
            *source = push(*source, srcTopDisk);
            *source = push(*source, dstTopDisk);
            // printf("Move disk %d from %c to %c\n",dstTopDisk, d, s);
        }

        // if dest top disk is bigger than source top disk then push it back 
        // then the source top disk above
        else{
            *dest = push(*dest, dstTopDisk);
            *dest = push(*dest, srcTopDisk);
            // printf("Move disk %d from %c to %c\n",srcTopDisk, s, d);
        }
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
    if(st.top < 0) return 1;
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
    if(emptyStack(*st)) {
        printf("Pop operation can't be done ,Stack is empty \n");
    }
    int val = st->arr[st->top];
    st->top--;
    return val;
}

void printStack(stack st) {
    if(emptyStack(st)) printf("The stack is empty \n");
    else {
        for(int i = 0; i <= st.top; i++) {
        printf("%d  ", st.arr[i]);
        }
    }
}