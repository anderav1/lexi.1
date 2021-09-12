#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "log.h"

// driver program
int main(int argc, char* argv[]) {
	char c;
	int sec = 5;

	// check for optional args
	while ((c = getopt(argc, argv, "ht:")) != -1) {
		switch (c) {
		case 'h':
			// display help message

			// terminate
			exit(1);
		case 't':
			// assign time interval variable
			sec = atoi(optarg);
			break;
		default:
			break;
		}
	}	
	
	// check for output filename arg
	char* ofilename;
	char* defaultfilename = "messages.log";
	if (argv[optind] != NULL) {
		ofilename = (char*)malloc(strlen(argv[optind]));
		strcpy(ofilename, argv[optind]);
	} else {
		ofilename = (char*)malloc(strlen(defaultfilename));
		strcpy(ofilename, defaultfilename);
	}

	// read the messages in from a txt file
	FILE* fp = fopen("messages.txt", "r");
	int linesize = 256;
	char* line = (char*)malloc(linesize);
	while (fgets(line, linesize, fp)) { // read each line of txt file
		char type = line[0];
		line++;
		line++;
		char* msg = line;
		addmsg(type, msg);

		// wait between messages
		srand(time(NULL));
		int waittime = rand() % ((sec*2) + 1);
		sleep(waittime);
	}

	free(line);
	fclose(fp);
	
	// run savelog func
	if (savelog(ofilename) == 0) {
		printf("savelog function successful: Log saved to file %s\n", ofilename);
	} else {
		puts("savelog function failed\n");
		return(-1);
	}

	// run getlog func
	char* logstring = (char*)malloc(256);
	logstring = getlog();
	if (logstring != NULL) {
		printf("getlog function successful: Log saved to string:\n %s\n", logstring);
	} else {
		puts("getlog function failed\n");
		return(-1);
	}
	free(logstring);

	// run clearlog func
	clearlog();
	return(0);
}
