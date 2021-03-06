/*************************************
Filename: des_display.c
Author : Cory Chenier & Vicknesh Babu
Assignment : 1
Date : November 6th 2019
Professor : Gerry Hurdle
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <limits.h>
#include <float.h>

#include "../../des_controller/src/ASS1.h"

int main (int argc, char* argv[])
{

	Person_T person;
	int rcvid;
	int previous_state = -1;
	int chid;
	int side;
	chid = ChannelCreate (0);
	if (chid == -1)
	{
		perror("Failed to create the channel.");
		exit (EXIT_FAILURE);
	}

	printf("Server PID is %d\n", getpid());


	while (1) {
		rcvid = MsgReceive (chid, &person, sizeof(person), NULL);
		if(person.currentState == EXIT){
			break;
		}
		side = person.side;
		if(person.currentState == previous_state || side == 0){
			printf("Invalid state\n");
		}
		else{
			switch(side){
			case LEFT:
				printf("%s", left_msg[person.currentState]);
				if(person.currentState == START){
					printf("%d\n",person.ID);
				}else if(person.currentState == WEIGHT){
					printf("%d\n",person.Weight);
				}
				break;
			case RIGHT:
				printf("%s", right_msg[person.currentState]);
				if(person.currentState == START){
					printf("%d\n",person.ID);
				}else if(person.currentState == WEIGHT){
					printf("%d\n",person.Weight);
				}
				break;

			}

			previous_state = person.currentState;
		}
		if (rcvid == -1){
			break;
		}

		MsgReply (rcvid, 1, NULL, 0);
	}

	ChannelDestroy(chid);
	return EXIT_SUCCESS;
}
