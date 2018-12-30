
#include "parseOpts.h"
#include "players2Game.h"

using namespace std;

int main(int argc, char const *argv[])
{

	switch (parseOpts(argc, argv)){
		case PLAYERS2:
			switch(players2Game()){
				case WIN_A:
					printf("Player A won!\n");
					break;
				case DRAW:
					printf("It's a draw!\n");
					break;
				case WIN_B:
					printf("Player B won\n");
					break;
			}
			break;
		case AI:
			//AI
			break;
		case PARSE_ERR:
			printf("Argument parsing error\n");
			break;
	}

	return 0;
}
