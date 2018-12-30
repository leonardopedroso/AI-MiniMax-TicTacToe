
#include "TTTgrid.h"

TTTgrid::TTTgrid(){

	for(char i = 0; i < SIZE_GRID; i++){
		for(char j = 0; j < SIZE_GRID; j++){
			grid[i][j] = BLANK;
		}
	}

}

void TTTgrid::display(){

	printf("--------------------------\n");
	printf("+ - + - + - +\n");
	unsigned char c;
	for(char i = 0; i < SIZE_GRID; i++){
		for(char j = 0; j < SIZE_GRID; j++){

			if(j == 0)
				printf("|");

			switch (grid[i][j]){
				case BLANK:
					c = BLANK_CHAR;
					break;
				case CROSS:
					c = CROSS_CHAR;
					break;
				case BALL:
					c = BALL_CHAR;
					break;
			}

			printf(" %c ", c);

			if(j == SIZE_GRID -1){
				printf("|\n");
				printf("+ - + - + - +\n");
			}
			else
				printf("|");

		}
	}
	printf("--------------------------\n");
}

void TTTgrid::add(char i, char j, char symbol){

	grid[i][j] = symbol;
}

char TTTgrid::status(){

	return WIN_A;
}

