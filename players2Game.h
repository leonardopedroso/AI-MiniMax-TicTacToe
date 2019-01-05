#include "baseHeader.h"

#include <time.h>
#include "AIv1.h"

#define ASCII_OFFSET 48

char players2Game(char MODE);
void getHumanMove(TTTgrid * game, char * move, char * player);
//void updateNextPlayer(char * nextplayer);
//char symbol(char nextplayer);
char moveIsValid(TTTgrid * game, char move1, char move2);
