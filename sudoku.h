#ifndef _SUDOKU_H_
#define _SUDOKU_H_

int checkRow(int** board, int row, int num);
int checkColumn(int** board, int column, int num);
int checkBlock(int** board, int row, int column, int num);


#endif