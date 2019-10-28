#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>

#include "ASS1.h"

int main (int argc, char* argv[])
{

	Person_T person;

	display_response_t response;

    chid = ChannelCreate (0);
    if (chid == -1)
    {
    	perror("Failed to create the channel.");
    	exit (EXIT_FAILURE);
    }

    printf("Server PID is %d\n", getpid());


    while (1) {
        rcvid = MsgReceive (chid, &person, sizeof(person), NULL);

        person_state = person.currentState;

        if (rcvid == -1){
        	break;
        }
        if(person_state == LEFT_SCAN){
        	response.msg = "Enter the Person's ID:\n";
        }
        else if(person_state == RIGHT_SCAN){
        	response.msg = "Enter the Person's ID:\n";
       	}
        else if(person_state == GLU_STATE){
        	response.msg = "Left door unlocked\n";
        }
        else if(person_state == GRU_STATE){
        	response.msg = "Right door unlocked\n";
        }
        else if(person_state == LO_STATE){
        	response.msg = "Left door open\n";
        }
        else if(person_state == RO_STATE){
        	response.msg ="Right door open\n";
        }
        else if(person_state == WEIGHT_STATE){
        	response.msg ="Enter your weight:\n";
        }
        else if(person_state == LEFT_CLOSE_STATE){
        	response.msg ="Left door close\n";
        }
        else if(person_state == RIGHT_CLOSE_STATE){
        	response.msg ="Right door close\n";
        }
        else if(person_state == GL_LOCK_STATE){
        	response.msg ="Guard left locked\n";
        }
        else if(person_state == GL_LOCK_STATE){
        	response.msg ="Guard right locked\n";
        }
        else if(person_state == EXIT){
        	response.msg = "Exiting.";
        }
        else{
        	response.errorMsg ="Invalid input.\n";
        }
        MsgReply (rcvid, 1, &response, sizeof (response));
    }

   ChannelDestroy(chid);
   return EXIT_SUCCESS;
}
