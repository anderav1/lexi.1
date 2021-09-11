#include <string.h>
#include "log.h"

// log_t* headptr and log_t* tailptr defined in log.c

// getlog function
// assign the contents of the log to a string, then return a ptr to the string
char* getlog(void) {
	char* logstr;
	int strsize = sizeof(char*)
	
	// allocate memory for the string ptr
	char* logstr = (char*)malloc(/*?????*/);

	log_t* currentnode = headptr;

	while (currentnode != NULL) {
		// append node's contents to logstr
		char* nodestr = nodestring(currentnode);
		strcat(logstr, nodestr);
	}
	
	// copy the log into the string
	//strcpy(logstr, /*??????*/);	
	
	// return a ptr to the string
	return logstr;
}
