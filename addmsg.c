#include <errno.h>
#include <stdio.h>
#include "log.h"

// log_t* headptr and log_t* tailptr defined in log.c

// addmsg function
// create a new data_t struct and insert it at the end of the log list
// returns -1 if msg type is invalid or node cannot be added 
int addmsg(const char type, const char* msg) {
	// check for valid msg type
	char c = toupper(type);
	if (c != 'I' && c != 'W' && c != 'E' && c != 'F') {
		// issue an error: invalid msg type
		// set errno=EINVAL, invalid argument
		//
		//errno = EINVAL;
		perror("Message failed to save to log");
		return(-1);
	}	

	// get current time
	time_t tm;
	time(&tm); // tm now stores the time

	// allocate space for new log node
	log_t* newnode;
	int size = sizeof(log_t) + strlen(msg) + 1;
	//ensure that node can be added
	if ((newnode = (log_t*)(malloc(nodesize))) == NULL) {
		// set errno using perror
		//
		//
		perror("Node creation failed");
		return(-1);
	}

	newnode->item.time = tm;
	newnode->item.type = c;
	newnode->item.string = (char*)newnode + sizeof(log_t);
	strcpy(newnode->item.string, msg);

	// link the node to the end of the list
	newnode->next = NULL;
	if (headptr = NULL)
		headptr == newnode;
	else
		tailptr->next = newnode;
	tailptr = newnode;	
}
