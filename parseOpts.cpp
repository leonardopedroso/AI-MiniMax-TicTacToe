#include "parseOpts.h"

char parseOpts(int argc, char const *argv[]){

	for(char i = 1; i <= argc; i++){
		if(!strcmp(PLAYERS2_STR,argv[i])){
			return PLAYERS2;
		}else if(!strcmp(AI_STR,argv[i])){
			return AI;
		}else
			return PARSE_ERR;
	}
	return PARSE_ERR;
}


