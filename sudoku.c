#include "sudoku.h"
#include "board.h"

int main() {
    int** board = readFile();
    printBoard(board);

    return 0;
}