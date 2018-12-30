#makefile
all: tictactoe

TTTgrid.o: TTTgrid.cpp TTTgrid.h
	g++ -c  TTTgrid.cpp

parseOpts.o: parseOpts.cpp parseOpts.h
	g++ -c parseOpts.cpp

players2Game.o: players2Game.cpp players2Game.cpp TTTgrid.h
	g++ -c players2Game.cpp 

tictactoe.o: tictactoe.cpp players2Game.h
	g++ -c  tictactoe.cpp

tictactoe: tictactoe.o TTTgrid.o parseOpts.o players2Game.o
	g++  tictactoe.o TTTgrid.o players2Game.o  parseOpts.o -o tictactoe 

clean:
	rm TTTgrid.o parseOpts.o tictactoe.o players2Game.o tictactoe

run: 
	./tictactoe -p
