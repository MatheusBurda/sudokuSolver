all:
	gcc -o sudokuSolver sudoku.c board.c stack.c
	
clean:
	rm sudokuSolver