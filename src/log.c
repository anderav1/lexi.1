#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../log.h"

log_t* headptr = NULL;
log_t* tailptr = NULL;

// getters and setters for list ptrs
log_t* gethead() {
	return headptr;
}

void sethead(log_t* ptr) {
	headptr = ptr;
}

log_t* gettail() {
	return tailptr;
}

void settail(log_t* ptr) {
	tailptr = ptr;
}

// writenode function
// helper function that returns a string containing the contents of a single node
char* nodestring(log_t* node) {
	// assign storage for node string
	char* nodestr;
	int strsize = 45 + strlen(node->item.string);
	// check allocation
	if ((nodestr = (char*)malloc(strsize)) == NULL) {
		perror("Could not assign memory for node string");
		return NULL;
	}

	// format & write time
	char* timestr;
	struct tm* tp = localtime(&(node->item.time));
	if ((timestr = (char*)malloc(16)) == NULL) {
		perror("Could not assign memory for timestamp string");
		return NULL;
	}
	sprintf(timestr, "Time: %.2d:%.2d:%.2d\n", tp->tm_hour, tp->tm_min, tp->tm_sec);
	strcat(nodestr, timestr);
	free(timestr);

	// write type
	char* typestr;
	if ((typestr = (char*)malloc(17)) == NULL) {
		perror("Could not assign memory for message type");
		return NULL;
	}
	sprintf(typestr, "Message type: %c\n", node->item.type);
	strcat(nodestr, typestr);
	free(typestr);

	// write message
	char* msgstr;
	if ((msgstr = (char*)malloc(12 + strlen(node->item.string))) == NULL) {
		perror("Could not assign memory for message");
		return NULL;
	}
	sprintf(msgstr, "Message: %s\n\n", node->item.string);
	strcat(nodestr, msgstr);
	free(msgstr);

	return nodestr;
}
