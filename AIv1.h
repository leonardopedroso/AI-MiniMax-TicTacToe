#ifndef AIv1_h
#define AIv1_h

#include "baseHeader.h"
#include "TTTgrid.h"

#define M_INFINITY -128
#define P_INFINITY 127
#define PLAY_SIZE 9

class SEQ_MOVES
{
public:
	SEQ_MOVES(char PLAYER);

	char value;
	char moves[PLAY_SIZE];

	void addMove(char newMove, char idx);

private:

};

void getAiMove(TTTgrid game, char * nextMove);
void joinSEQ_MOVES(SEQ_MOVES * to, SEQ_MOVES * from, char idx);
void miniMax(TTTgrid game, SEQ_MOVES * moves, char PLAYER, char idxFreedom);
void updateNextPlayer(char * nextplayer);
char updateNextPlayerR(char nextplayer);
char symbol(char nextplayer);

#endif
