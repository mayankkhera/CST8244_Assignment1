/*************************************
Filename: ASS1.h
Author : Cory Chenier & Vicknesh Babu
Assignment : 1
Date : November 6th 2019
Professor : Gerry Hurdle
**************************************/
#define LEFT 1
#define RIGHT 2
struct Person {
	int ID;
	int Weight;
	int currentState;
	int side;
}typedef Person_T;

struct display_response {
	char   msg[128];
	char   errorMsg[128];
} typedef display_response_t;


#define STATES 13;
typedef enum {
	START = 0;
	ENTER_UNLOCK = 1;
	ENTER_OPEN = 2;
	WEIGHT = 3;
	ENTER_CLOSE = 4;
	ENTER_LOCK = 5;
	EXIT_UNLOCK = 6;
	EXIT_OPEM = 7;
	EXIT_CLOSE = 8;
	EXIT_LOCK = 9;
} States;

#define NUM_INPUTS 10
const char *left_side[NUM_INPUTS] = {
	"ls",
	"glu",
	"lo",
	"ws",
	"lc"
	"gll",
	"gru",
	"ro",
	"rc",
	"grl"
};
const char *right_side[NUM_INPUTS] = {
	"rs",
	"gru",
	"ro",
	"ws",
	"rc",
	"grl",
	"glu",
	"lo",
	"lc",
	"gll"
}




void SCAN_FUNC(char* input);
void UNLOCK_FUNC(char* input);
void OPEN_FUNC(char* input);
void WEIGHT_FUNC(char* input);
void CLOSE_FUNC(char* input);
void GUARD_EXIT_UNL_FUNC(char* input);
void GUARD_EXIT_OPEN_FUNC(char* input);
void EXIT_CLOSE_FUNC(char* input);
void GUARD_EXIT_LOCK_FUNC(char* input);
void EXIT_FUNC(char* input);

void(*STATE_HANDLER[10])(char* input);

