/****************************************************/
/* 			    Estruturas de Dados  1 			    */
/*          Aluno: Matheus Augusto Burda            */
/*					RA: 1661736						*/
/*               Trabalho Prático                   */
/*                 Sudoku Solver                    */
/****************************************************/

#include "sudoku.h"
#include "board.h"
#include "stack.h"

/* Check if row contains the num */
int checkRow(int** board, int row, int num) {
    for (int i = 0; i < SIZE; i++)
        if (board[row][i] == num)
            return 1;
    return 0;
}

/* Check if the column contains the num */
int checkColumn(int** board, int column, int num) {
    for (int i = 0; i < SIZE; i++)
        if (board[i][column] == num)
            return 1;
    return 0;
}

/* Check if number already exist on block.
    Blocks:
    00|01|02
    10|11|12 
    20|21|22
*/
int checkBlock(int** board, int row, int column, int num) {

    row /= 3;
    row *= 3;
    column /= 3;
    column *= 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + row][j + column] == num) 
                return 1;
        }
    }
    return 0;
}

int main() {
    int** board = createBoard();
    printBoard(board);

    printf("%d\n", checkBlock(board, 6, 0, 8));

    freeBoard(board);
    return 0;
}

/* for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            
        }
    } */