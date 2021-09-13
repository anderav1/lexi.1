#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "log.h"

// driver program
int main(int argc, char* argv[]) {
	char c;
	int sec = 0;

	// check for optional args
	while ((c = getopt(argc, argv, "ht:")) != -1) {
		switch (c) {
		case 'h':
			// display help message
			puts("LIBLOG HELP\n");
			puts("Run the driver program with the command 'drive [-h] [-t SEC] [LOGFILE]'\n");
			puts("-h -- Get help");
			puts("-t SEC -- Print each message every SEC seconds, on average");
			puts("LOGFILE -- output file to save the log to");

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

	// run addmsg function
	// read the messages in from a txt file
	FILE* fp = fopen("messages.txt", "r");
	int linesize = 256;
	char* line = (char*)malloc(linesize);
	while ((fgets(line, linesize, fp)) != NULL) {
		char type = line[0];
		if (isalpha(type)) {
			addmsg(type, line);

			// wait between messages
			srand(time(NULL));
			int waittime = rand() % ((sec*2) + 1);
			sleep(waittime);
		} else {
			break;
		}
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
	
	free(ofilename);
	
	// run getlog func
	char* logstring = (char*)malloc(2560);
	logstring = getlog();
	if (logstring != NULL) {
		printf("getlog function successful: Log saved to string:\n\n %s", logstring);
	} else {
		puts("getlog function failed\n");
		return(-1);
	}
	free(logstring);

	// run clearlog func
	clearlog();
	puts("Released memory allocated to log");

	puts("All funcs tested");
	return(0);
}
