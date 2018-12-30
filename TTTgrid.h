#include <stdio.h>
#include <stdlib.h>

#define SIZE_GRID 3

#define BLANK 0
#define CROSS 1
#define BALL  2

#define BLANK_CHAR 32
#define CROSS_CHAR 88
#define BALL_CHAR 79

#define WIN_A      1
#define DRAW       0
#define WIN_B      -1
#define UNFINISHED 2

class TTTgrid
{
public:

	//Constructor & destructor
	TTTgrid();
	//~TTTgrid();

	//Variables 
	char grid[SIZE_GRID][SIZE_GRID];

	//Methods
	void display();
	void add(char i, char j, char symbol);
	char status();

private:


};

