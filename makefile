all:
	gcc -o sudokuSolver src/sudoku.c src/board.c src/stack.c
	
clean:
	rm sudokuSolver