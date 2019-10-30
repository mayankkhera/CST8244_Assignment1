#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <limits.h>
#include <float.h>

#include "ASS1.h"
int setStartSide(char* side);
Person_T person;
int rcvid;
int main(int argc, char* argv) {
	
	if (argc != 2){
		fprintf(stderr,"Invalid number of arguments.");
		exit(EXIT_FAILURE);
	}

	pid_t display_pid = atoi(argv[1]);
	int chid;
	int error;
	char* input_msg;
	char* display_msg;
	int coid;


	chid = ChannelCreate(0);

	if(chid == -1){
		fprintf(stderr, "Failed to create a channel");
		exit(EXIT_FAILURE);
	}
	coid = ConnectAttach(ND_LOCAL_NODE, display_pid, 1, _NTO_SIDE_CHANNEL, 0);
	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	while(1){
	rcvid = MsgReceive(chid, input_msg, sizeof(input_msg), NULL);
	int side = setStartSide(input_msg);
	if (side == -1){
		error = 0;
		MsgReply(rcvid, EOK,error_msg[error] , sizeof(error_msg[error]));
	}
	(*STATE_HANDLER[person.currentState])(input_msg);


	}







	return EXIT_SUCCESS;
}
int setStartSide(char* side){
	if(strcmp(side,"ls") == 0){
			person.side = LEFT;
			person.currentState = START;
			return 0;

	}
	else if(strcmp(side,"rs") == 0){
			person.side = RIGHT;
			person.currentState = START;
			return 0;
		}else{
			return -1;
		}

}
void SCAN_FUNC(char* input){

	person.ID = atoi(input);

	person.currentState++;
}
void UNLOCK_FUNC(char* input){
	if(person.side == LEFT){


		}
	else if(person.side == RIGHT){

		}
}
void OPEN_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void WEIGHT_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void CLOSE_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void GUARD_EXIT_UNL_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void GUARD_EXIT_OPEN_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void EXIT_CLOSE_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void GUARD_EXIT_LOCK_FUNC(char* input){
	if(person.side == LEFT){


		}
		else if(person.side == RIGHT){

		}
}
void EXIT_FUNC(char* input){
	person.currentState = START;
}
