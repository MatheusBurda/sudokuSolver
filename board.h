#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

#define NAME_OF_FILE "board.txt"

void freeBoard(int** board);
int** createBoard();
int** readFile();
void printBoard(int** board);

#endif