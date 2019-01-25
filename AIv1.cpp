/*
- NO ALPHA BETA PRUNING
- NO DYNAMIC MEMORY ALLOCATION
- NO SIMETRY OPTIMIZATION
- COMPUTES DECISION TREE EVERY TIME
*/



#include "AIv1.h"

SEQ_MOVES::SEQ_MOVES(char PLAYER){
	
	if(PLAYER == PLAYER_A){
		value = P_INFINITY;
	}else{
		value = M_INFINITY;
	}

	for(char i = 0; i< PLAY_SIZE; i++){
		moves[i] = M_INFINITY;
	}
}

void SEQ_MOVES::addMove(char newMove, char idx){

	moves[idx] = newMove;
}

void getAiMove(TTTgrid game, char * nextMove){

	SEQ_MOVES moves(PLAYER_B);
	miniMax(game, &moves, PLAYER_A, 0);

	for(char i = PLAY_SIZE-1; i >= 0; i--){
		if(moves.moves[i]!= M_INFINITY)
			*nextMove = moves.moves[i];
	}

	#ifdef DEBUG

	printf("Final  best moves\n");
	for (int i = 0; i < PLAY_SIZE; ++i){	
		printf("%d ",moves.moves[i]);
	}	printf("\n");

	#endif

}

void miniMax(TTTgrid game, SEQ_MOVES * moves, char PLAYER, char idxFreedom){

	if(game.status() != UNFINISHED){
		moves->value = game.status();
		//printf("Game finished just returned %d\n", game.status());
		return;
	}

	for(char i = 0; i < SIZE_GRID; i++){
		for(char j = 0; j < SIZE_GRID; j++){
			if(game.grid[i][j] == BLANK){

				SEQ_MOVES moveTry(PLAYER);
				moveTry.addMove(i*SIZE_GRID+j, idxFreedom);

				TTTgrid gameTry;
				copyTTTgrid(&gameTry, &game);
				gameTry.add(i*SIZE_GRID+j, symbol(PLAYER));
				
				
				#ifdef DEBUG
				printf("New try on %d %d\n",i,j);
				gameTry.display();
				#endif
	
				miniMax(gameTry, &moveTry, updateNextPlayerR(PLAYER), idxFreedom+1);


				if(PLAYER == PLAYER_A){
					if(moveTry.value > moves->value){
						joinSEQ_MOVES(moves, &moveTry, idxFreedom);
					}
				}
				else{
					if(moveTry.value < moves->value){
						joinSEQ_MOVES(moves, &moveTry, idxFreedom);
					}
				}

				#ifdef DEBUG
				printf("Best moves for each with freedom %d\n", idxFreedom);
				for (int i = 0; i < PLAY_SIZE; ++i){	
					printf("%d ",moves->moves[i]);
				}	printf("value %d\n",moves->value);

				#endif

			}

		}

	}

}

void joinSEQ_MOVES(SEQ_MOVES * to, SEQ_MOVES * from, char idx){

	to->value = from->value;

	for(char i = idx; i < PLAY_SIZE; i++){
		to->moves[i] = from->moves[i];
	}

}

void updateNextPlayer(char * nextplayer){
	
	if(*nextplayer == PLAYER_A)
		*nextplayer = *nextplayer+1;
	else
		*nextplayer = *nextplayer-1;
}

char updateNextPlayerR(char nextplayer){
	
	if(nextplayer == PLAYER_A)
		return nextplayer+1;
	return nextplayer-1;
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
