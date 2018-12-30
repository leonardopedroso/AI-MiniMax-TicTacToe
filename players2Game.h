
#include <stdlib.h>
#include <stdio.h>

#include "TTTgrid.h"

#define PLAYER_A 65
#define PLAYER_B 66

char players2Game();
void getMove(char move[2], char nextplayer);
void updateNextPlayer(char * nextplayer);
char symbol(char nextplayer);