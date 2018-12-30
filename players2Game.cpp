
#include "players2Game.h"


char players2Game(){

	TTTgrid game;

	char nextplayer = PLAYER_A;
	char move[2];

	while(game.status() == UNFINISHED){

		game.display();
		getMove(move,nextplayer);
		updateNextPlayer(&nextplayer);
		game.add(move[0], move[1], symbol(nextplayer));
	}

	return game.status();
}

void getMove(char move[2], char nextplayer){

	do{
		printf("Move for player %c: ", nextplayer);

	}while(scanf("%d,%d", (int *)&move[0], (int *)&move[1])!=2);

}

void updateNextPlayer(char * nextplayer){
	if(*nextplayer == PLAYER_A)
		*nextplayer = *nextplayer+1;
	else
		*nextplayer = *nextplayer-1;
}

char symbol(char nextplayer){
	switch(nextplayer){
		case PLAYER_A:
			return CROSS_CHAR;
			break;
		case PLAYER_B:
			return BALL_CHAR;
			break;
	}

	return BLANK_CHAR;
}

