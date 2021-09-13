#include <stdio.h>
#include <string.h>
#include "../log.h"

// log_t* headptr and log_t* tailptr defined in log.c
//extern log_t* headptr;
//extern log_t* tailptr;

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
		char* str = nodestring(currentnode);
		fprintf(fp, "%s", str);
		currentnode = currentnode->next;
	}

	fclose(fp);
	return(0);
}

