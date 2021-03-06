/****************************************************/
/* 			    Estruturas de Dados  1 			    */
/*          Aluno: Matheus Augusto Burda            */
/*					RA: 1661736						*/
/*               Trabalho Prático                   */
/*                 Sudoku Solver                    */
/****************************************************/

#include "board.h"

/* Creates a board of 9x9 int. */
int** createBoard() {
    int** board;

    board = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
        board[i] = (int*)malloc(SIZE * sizeof(int));

    board = readFile(board);

    return board;
}

/* Deallocates the board. */
void freeBoard(int** board) {
    for (int i = 0; i < SIZE; i++)
        free(board[i]);
    free(board);
}

/* Reads the "board.txt" file and returns a int matrix containing the numbers of the sudoku. */
int** readFile(int** board) {
    int i, j;
    FILE* fp;

    fp = fopen(NAME_OF_FILE, "r");

    if (fp == NULL) {
        printf("ERROR: couldnt open %s.\n", NAME_OF_FILE);
        exit(1);
    }

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            fscanf(fp, "%d ", &board[i][j]);

    fclose(fp);
    return board;
}

/* Function to print the whole Sudoku Board. */
void printBoard(int** board) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != 0)
                printf("%d ", board[i][j]);
            else
                printf("  ");
            if ((j + 1) % 3 == 0 && j != 8)
                printf("| ");
        }
        putchar('\n');
        if ((i + 1) % 3 == 0 && i != 8)
            printf("—————————————————————\n");
    }
}
