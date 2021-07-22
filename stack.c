/****************************************************/
/* 			    Estruturas de Dados  1 			    */
/*          Aluno: Matheus Augusto Burda            */
/*					RA: 1661736						*/
/*               Trabalho Prático                   */
/*                 Sudoku Solver                    */
/****************************************************/

#include "stack.h"

Stack* createStack() {
    return NULL;
}

void freeStack(Stack* s) {
    Stack* aux = s;
    while (aux != NULL) {
        aux = s->next;
        free(s);
        s = aux;
    }
}

Stack* push(Stack* s, int col, int row) {
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->col = col;
    node->row = row;
    node->next = s;
    return node;
}

Stack* pop(Stack* s) {
    if (emptyStack(s)) {
        printf("Stack empty, can't pop.\n");
        exit(1);
    }
    Stack* next = s->next;
    free(s);
    return next;
}

int emptyStack(Stack* s) {
    if (s == NULL)
        return 1;
    return 0;
}
