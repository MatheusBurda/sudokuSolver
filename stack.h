#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int col;
    int row;
    struct stack* next;
} Stack;

Stack* createStack();

void freeStack(Stack* s);

Stack* push(Stack* s, int col, int row);

Stack* pop(Stack* s);

int top(Stack* s);

int emptyStack(Stack* s);

#endif