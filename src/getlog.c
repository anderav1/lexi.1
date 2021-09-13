#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../log.h"

// log_t* headptr and log_t* tailptr defined in log.c
extern log_t* headptr;
extern log_t* tailptr;

// getlog function
// assign the contents of the log to a string, then return a ptr to the string
char* getlog(void) {
	char* logstr;
	int size = 2560;
	
	// allocate memory for the string ptr
	if ((logstr = (char*)malloc(size)) == NULL) {
		perror("Could not allocate memory for log string");
		return NULL;
	}

	log_t* currentnode = headptr;

	while (currentnode != NULL) {
		// append node's contents to logstr
		strcat(logstr, nodestring(currentnode));
		currentnode = currentnode->next;
	}
	// return a ptr to the string
	return logstr;
}
