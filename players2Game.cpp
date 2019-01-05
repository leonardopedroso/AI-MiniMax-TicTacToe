
#include "players2Game.h"

//#define DEBUG

char players2Game(char MODE){

#ifdef DEBUG

	TTTgrid game;
	char nextplayer = PLAYER_A;
	char move;

	game.add(0,symbol(PLAYER_A));
	game.add(4,symbol(PLAYER_A));
	game.add(1,symbol(PLAYER_B));
	game.add(2,symbol(PLAYER_B));
	game.add(3,symbol(PLAYER_B));
	game.add(7,symbol(PLAYER_B));

	game.display();

	move = -1;
	getAiMove(game, &move);

	printf("move %d\n", move);

	return 7;

#else

	TTTgrid game;
	srand(time(NULL));
	char nextplayer = PLAYER_A + rand()%2;
	char move;

	do{
		game.display();

		if(MODE == PLAYERS2 || nextplayer == PLAYER_B){
			getHumanMove(&game, &move, &nextplayer);
		}else{
			move = -1;
			getAiMove(game, &move);
			printf("move %d\n", move);
		}
		game.add(move, symbol(nextplayer));
		updateNextPlayer(&nextplayer);

	}while(game.status() == UNFINISHED);

	game.display();

	return game.status();
#endif

}

void getHumanMove(TTTgrid * game, char * move, char * player){

	char move1;
	char move2;

	char convertions;

	do{
		printf("Move for player %c: ", *player);
		convertions = scanf("%c,%c", &move1, &move2);

		char c;
		do{
			c = getchar();
		}while(c!='\n');

	} while( convertions != 2 || !moveIsValid(game, move1-ASCII_OFFSET, move2-ASCII_OFFSET));

	*move = (move1-ASCII_OFFSET)*SIZE_GRID+(move2-ASCII_OFFSET);
}

/*void updateNextPlayer(char * nextplayer){
	
	if(*nextplayer == PLAYER_A)
		*nextplayer = *nextplayer+1;
	else
		*nextplayer = *nextplayer-1;
}*/

/*char symbol(char nextplayer){

	switch(nextplayer){
		case PLAYER_A:
			return CROSS;
			break;
		case PLAYER_B:
			return BALL;
			break;
	}
	return BLANK_CHAR;
}*/


char moveIsValid(TTTgrid * game, char move1, char move2){

	if(move1>=0 && move1<SIZE_GRID && move2>=0 && move2<SIZE_GRID){
		if(game->grid[move1][move2] == BLANK)
			return TRUE;
	}
	return FALSE;
}

