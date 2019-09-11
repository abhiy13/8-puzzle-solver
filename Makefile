CC = g++

VER = -std=c++14

FLAGS = -c -Wall

compile: main.o Board.o Solver.o
	$(CC) Board.o Solver.o main.o -o run

main.o: main.cpp
	$(CC) $(VER) $(FLAGS) main.cpp

Board.o: Board.cpp ./includes/Board.h
	$(CC) $(VER) $(FLAGS) Board.cpp

Solver.o: Solver.cpp ./includes/Solver.h
	$(CC) $(VER) $(FLAGS) Solver.cpp

clean:
	rm -rf *o run
