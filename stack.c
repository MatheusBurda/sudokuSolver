/****************************************************/
/* 			    Estruturas de Dados  1 			    */
/*          Aluno: Matheus Augusto Burda            */
/*					RA: 1661736						*/
/*                    Lista 4                       */
/*                  Exercício 2                     */
/****************************************************/

#include "stack.h"

/*Função para criar uma pilha vazia (não criar nenhum nó, só devolver NULL)!*/
Stack* create_stack() {
    return NULL;
}

/*Função para liberar uma pilha nó por nó*/
void free_stack(Stack* s) {
    Stack* aux = s;
    while (aux != NULL) {
        aux = s->next;
        free(s);
        s = aux;
    }
}

/*Função para empilhar um elemento (inserir na cabeça da lista encadeada)!*/
Stack* push(Stack* s, int elem) {
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->info = elem;
    node->next = s;
    return node;
}

/*Função para desempilhar um elemento (remover da cabeça da lista encadeada)!*/
Stack* pop(Stack* s) {
    if (empty_stack(s)) {
        printf("Stack empty, can't pop.\n");
        exit(1);
    }
    Stack* next = s->next;
    free(s);
    return next;
}

/*Função para retornar o elemento no topo da pilha (cabeça da lista encadeada) sem desempilhar!*/
int top(Stack* s) {
    if (s == NULL) {
        printf("Segmentation fault.\n");
        exit(1);
    }
    return s->info;
}

/*Função para testar se uma pilha está vazia!*/
int empty_stack(Stack* s) {
    if (s == NULL)
        return 1;
    return 0;
}
