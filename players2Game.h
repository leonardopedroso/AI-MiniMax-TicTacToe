
#include <stdlib.h>
#include <stdio.h>

#include <iostream> 
#include <ios> 

#include "TTTgrid.h"

#define PLAYER_A 65
#define PLAYER_B 66

#define ASCII_OFFSET 48

#define TRUE 1
#define FALSE 0

char players2Game();
void getMove(TTTgrid * game, char * move, char * player);
void updateNextPlayer(char * nextplayer);
char symbol(char nextplayer);
char moveIsValid(TTTgrid * game, char move1, char move2);
