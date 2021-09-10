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
	log_t* nextnode;

	while (currentnode != NULL) {
		// print node data to file
		// write time
		struct tm* tp = localtime(&(currentnode->item.time));
		char* timestr;
		sprintf(timestr, "%.2d:%.2d:%.2d", tp->tm_hour, tp_tm_min, tp->tm_sec);
		fprintf(fp, "Time: %s\n", timestr);
		
		// write msg type
		fprintf(fp, "Message type: %c\n", currentnode->item.type);

		// write msg
		fprintf(fp, "Message: %s\n\n", currentnode->item.string);	
	}

	fclose(fp);
	return(0);
}

