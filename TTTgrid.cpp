
#include "TTTgrid.h"

TTTgrid::TTTgrid(){

	for(char i = 0; i < SIZE_GRID; i++){
		for(char j = 0; j < SIZE_GRID; j++){
			grid[i][j] = BLANK;
		}
	}


}

void TTTgrid::display(){

	printf("----------------------\n");
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
	printf("----------------------\n");
}

void TTTgrid::add(char move, char symbol){

	grid[move/SIZE_GRID][move%SIZE_GRID] = symbol;
}

char TTTgrid::status(){

	// Run rows
	for(char i = 0; i < SIZE_GRID; i++){

		if(grid[i][0] != BLANK){
			for(char j = 1; j < SIZE_GRID; j++){

				if(grid[i][j] == grid[i][0]){
					printf("same\n");
					if(j == SIZE_GRID-1){
						return grid[i][0]-1;
					}else
						continue;
				}else
					break;
			}
		}
		
	}

	// Run columns
	for(char j = 0; j < SIZE_GRID; j++){
		if(grid[0][j] != BLANK){	
			for(char i = 1; i < SIZE_GRID; i++){
				if(grid[i][j] == grid[0][j]){
					if(i == SIZE_GRID-1){
						return grid[0][j]-1;
					}else
						continue;
				}else{
					break;
				}
			}
		}
	}

	// Principal diagonal
	if(grid[0][0] != BLANK){	
		for (char i = 1; i < SIZE_GRID; ++i){
			if(grid[i][i] == grid[0][0]){
				if(i == SIZE_GRID-1){
					return grid[0][0]-1;
				}else{
					continue;
				}
			}else{
				break;
			}
		}
	}

	// Secondary diagonal
	if(grid[0][SIZE_GRID-1] != BLANK){
		for (char i = 1; i < SIZE_GRID; ++i){
			if(grid[i][SIZE_GRID-1-i] == grid[0][SIZE_GRID-1]){
				if(i == SIZE_GRID-1){
					return grid[0][SIZE_GRID-1]-1;
				}else{
					continue;
				}
			}else{
				break;
			}
		}
	}

	// Check unfinishec
	for(char i = 0; i < SIZE_GRID; i++){
		for(char j = 0; j < SIZE_GRID; j++){
			if(grid[i][j] == BLANK){
				return UNFINISHED;
			}
			
		}
	}

	return DRAW;
}

