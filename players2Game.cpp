
#include "players2Game.h"

char players2Game(){

	TTTgrid game;

	char nextplayer = PLAYER_A;
	char move;

	do{

		game.display();
		getMove(&game, &move, &nextplayer);
		game.add(move, symbol(nextplayer));
		updateNextPlayer(&nextplayer);

	}while(game.status() == UNFINISHED);

	game.display();

	return game.status();
}

void getMove(TTTgrid * game, char * move, char * player){

	char move1;
	char move2;

	printf("Move for player %c: ", *player);
	

	/*while(scanf("%c,%c", &move1, &move2) != 2 || !moveIsValid(game, move1-ASCII_OFFSET, move2-ASCII_OFFSET)){
		char c;
		do{
			c = getchar();
			printf("got one %d\n",c);
		}while(c!='\n');

		printf("Move for player %c: ", *player);
	}*/
	
	char convertions;

	do{

		convertions = scanf("%c,%c", &move1, &move2);

		char c;
		do{
			c = getchar();
		}while(c!='\n');

	} while( convertions != 2 || !moveIsValid(game, move1-ASCII_OFFSET, move2-ASCII_OFFSET));

	*move = (move1-ASCII_OFFSET)*SIZE_GRID+(move2-ASCII_OFFSET);
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
			return CROSS;
			break;
		case PLAYER_B:
			return BALL;
			break;
	}
	return BLANK_CHAR;
}


char moveIsValid(TTTgrid * game, char move1, char move2){

	if(move1>=0 && move1<SIZE_GRID && move2>=0 && move2<SIZE_GRID){
		if(game->grid[move1][move2] == BLANK)
			return TRUE;
	}
	return FALSE;
}

