#include <stdio.h>
#include "log.h"

// log_t* headptr and log_t* tailptr defined in log.c

// savelog function
// saves all logged msgs to disk file filename
int savelog(char* filename) {
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		perror("File cannot be written");
		return(-1);
	}

	fprintf(fp, "MESSAGE LOG\n\n");

	// traverse the list, writing each node's contents to the file
	log_t* currentnode = headptr;

	while (currentnode != NULL) { // print node data to file
		str = nodestring(currentnode);
		fprintf(fp, "%s", str);
		currentnode = currentnode->next;
	}

	fclose(fp);
	return(0);
}

// writenode function
// helper function that returns a string containing the contents of the node
char* nodestring(log_t* node) {
	char* nodestr = NULL;
	// format & write time
	struct tm* tp = localtime(&(node->item.time));
	char* timestr;
	sprintf(timestr, "Time: %.2d:%.2d:%.2d\n", tp->tm_hour, tp->tm_min, tp->tm_sec);
	strcat(nodestr, timestr);

	// write type
	char* typestr;
	sprintf(typestr, "Message type: %c\n", node->item.type);
	strcat(nodestr, typestr);

	// write message
	char* msgstr;
	sprintf(msgstr, "Message: %s\n\n", node->item.string);
	strcat(nodestr, msgstr);

	return nodestr;
}
