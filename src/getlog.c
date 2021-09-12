#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

// log_t* headptr and log_t* tailptr defined in log.c

// getlog function
// assign the contents of the log to a string, then return a ptr to the string
char* getlog(void) {
	char* logstr;
	int size = 50;
	
	// allocate memory for the string ptr
	if ((logstr = (char*)malloc(size)) == NULL) {
		perror("Could not allocate memory for log string");
		return NULL;
	}

	log_t* currentnode = headptr;

	while (currentnode != NULL) {
		size += strlen(currentnode->item.string) + 45;
		if ((logstr = (log_t*)realloc(logstr, size)) == NULL) {
			perror("Could not allocate memory for log string");
			return NULL;
		}
		// append node's contents to logstr
		strcat(logstr, nodestring(currentnode));
	}
	
	// return a ptr to the string
	return logstr;
}
