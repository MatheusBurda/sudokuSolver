all:
	gcc -o sudoku sudoku.c board.c stack.c
	
clean:
	rm sudoku