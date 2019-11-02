#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <limits.h>
#include <float.h>
/*
 * Remember: MsgReceive and reply in this file is involved with Des_inputs,
 * MsgSend will send to display
 */
#include "ASS1.h"
int setStartSide(char* side);
Person_T person;

char* display_msg;
int coid = 0;
int main(int argc, char *argv[]) {
	int rcvid;
	if (argc != 2) {
		fprintf(stderr, "Invalid number of arguments.");
		exit(EXIT_FAILURE);
	}

	pid_t display_pid = atoi(argv[1]);
	int chid;
	int error;
	char input_msg[50];

	printf("Controller pid: %d\n", getpid());

	chid = ChannelCreate(0);

	if (chid == -1) {
		fprintf(stderr, "Failed to create a channel");
		exit(EXIT_FAILURE);
	}
	coid = ConnectAttach(ND_LOCAL_NODE, display_pid, 1, _NTO_SIDE_CHANNEL, 0);
	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		rcvid = MsgReceive(chid, input_msg, sizeof(input_msg), NULL);
		printf("%s", input_msg);
		if (strcmp(input_msg, "exit") == 0) {
			break;
		} else {
			int side = setStartSide(input_msg);
			if (side == -1) {
				error = 0;
				MsgReply(rcvid, EOK, error_msg[error],
						sizeof(error_msg[error]));
			}
			(*STATE_HANDLER[person.currentState])(input_msg);
		}

	}
}
int setStartSide(char* side) {
	if (strcmp(side, "ls") == 0) {
		person.side = LEFT;
		person.currentState = START;
		return 0;

	} else if (strcmp(side, "rs") == 0) {
		person.side = RIGHT;
		person.currentState = START;
		return 0;
	} else {
		return -1;
	}

}
void SCAN_FUNC(char* input) {
	if (MsgSend(coid, &person, sizeof(person), display_msg, sizeof(display_msg))
			== -1) {
		fprintf(stderr, "Unable to sendhhhh message\n");
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	printf("%s", display_msg);

	person.ID = atoi(input);
	person.currentState++;
}
void UNLOCK_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}return OPEN_FUNC

		}
	else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void OPEN_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
}
void WEIGHT_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void CLOSE_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void GUARD_EXIT_UNL_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void GUARD_EXIT_OPEN_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void EXIT_CLOSE_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void GUARD_EXIT_LOCK_FUNC(char* input){
	if(person.side == LEFT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}

		}
		else if(person.side == RIGHT){
			if (MsgSend (coid, &request, sizeof(request), &response, sizeof(response)) == -1) {
			fprintf (stderr, "Error during MsgSend\n");
			perror (NULL);
			exit (EXIT_FAILURE);
		}
		}
}
void EXIT_FUNC(char* input){
	person.currentState = START;
}
