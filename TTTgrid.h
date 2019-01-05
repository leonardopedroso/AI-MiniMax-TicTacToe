
#include "baseHeader.h"

#define BLANK 1
#define CROSS 2
#define BALL  0

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
	void add(char move, char symbol);
	char status();
	void displayRaw();

private:


};

void copyTTTgrid(TTTgrid * to, TTTgrid * from);

