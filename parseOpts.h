#ifndef parseOpts_h
#define parseOpts_h


#include "baseHeader.h"
#include <string.h>

#define PARSE_ERR 0
/*#define PLAYERS2  1
#define AI        2*/

#define PLAYERS2_STR "-p"
#define AI_STR       "-a"



char parseOpts(int argc, char const *argv[]);

#endif
