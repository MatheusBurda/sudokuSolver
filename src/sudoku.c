/****************************************************/
/* 			    Estruturas de Dados  1 			    */
/*          Aluno: Matheus Augusto Burda            */
/*					RA: 1661736						*/
/*               Trabalho Prático                   */
/*                 Sudoku Solver                    */
/****************************************************/

#include "sudoku.h"

#define STEP_BY_STEP 0

/* Recursive function to solve the sudoku. It needs the Stack of last steps, the sudoku board, and the i and j position to change. */
void solve(Stack* steps, int** board, int i, int j) {
    if (j >= SIZE) {
        j = 0;
        i++;
    }

    board[i][j] = getPossibleNumber(board, i, j);

    /* No possible number to fill */
    if (board[i][j] == 0) {
        if (emptyStack(steps)) {
            printf("ERROR: No possible solution for this problem.\n");
            freeBoard(board);
            freeStack(steps);
            exit(1);
        }

        /* Step back */
        i = steps->row;
        j = steps->col;
        steps = pop(steps);
    }
    /* Add step to Stack as a valid step */
    else {
        steps = push(steps, j, i);
        if (!getNextEmptyPos(board, &i, &j))
            return;
    }

    /* If want to print all the steps STEP_BY_STEP needs to be 1. */
    if (STEP_BY_STEP) {
        getchar();
        system("clear");
        printBoard(board);
    }

    /* Recursive call until exceed limits of board, caught by second if statement */
    solve(steps, board, i, j);
}

/* Check if row contains the num */
int checkRow(int** board, int row, int num) {
    for (int i = 0; i < SIZE; i++)
        if (board[row][i] == num)
            return 1;
    return 0;
}

/* Check if the column contains the num */
int checkColumn(int** board, int col, int num) {
    for (int i = 0; i < SIZE; i++)
        if (board[i][col] == num)
            return 1;
    return 0;
}

/* Check if number already exist on block.
    Blocks:
    00|01|02
    10|11|12 
    20|21|22
*/
int checkBlock(int** board, int row, int col, int num) {
    row /= 3;
    row *= 3;
    col /= 3;
    col *= 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + row][j + col] == num)
                return 1;
        }
    }
    return 0;
}

/* Return a possible number to be added to a row col position on board
    if not found a possible number, returns 0 */
int getPossibleNumber(int** board, int row, int col) {
    for (int i = board[row][col]; i <= SIZE; i++) {
        if (!checkBlock(board, row, col, i) && !checkColumn(board, col, i) && !checkRow(board, row, i))
            return i;
    }
    return 0;
}

/* Changes the row and col variables to a valid empty position. If theres no possible position it returns 0. */
int getNextEmptyPos(int** board, int* row, int* col) {
    int i, j = *col;

    for (i = *row; i < SIZE; i++) {
        for (j; j < SIZE; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
        j = 0;
    }
    return 0;
}

int main() {
    Stack* steps = createStack();
    int** board = createBoard();
    int i = 0, j = 0;

    printBoard(board);

    getNextEmptyPos(board, &i, &j);

    solve(steps, board, i, j);

    printf("\n———————Solução———————\n\n");
    printBoard(board);

    freeBoard(board);
    emptyStack(steps);
    return 0;
}
