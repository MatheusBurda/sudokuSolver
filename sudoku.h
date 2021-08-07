#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include "board.h"
#include "stack.h"
#include <stdio.h>

int checkRow(int** board, int row, int num);
int checkColumn(int** board, int col, int num);
int checkBlock(int** board, int row, int col, int num);
void solve(Stack* steps, int** board, int i, int j);
int getNextEmptyPos(int** board, int* row, int* col);
int getPossibleNumber(int** board, int row, int col);

#endif