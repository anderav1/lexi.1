#include <stdio.h>

// driver program
int main(int argc, char* argv[]) {
	char c;
	int sec;

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
	ofilename = (char*)malloc(strlen());
	strcpy(ofilename, "message.log");
	if (argv[optind] != NULL) {
		ofilename = (char*)malloc(strlen(argv[optind]));
		strcpy(ofilename, argv[optind]);
	} else {
		ofilename = (char*)malloc(strlen(defaultfilename));
		strcpy(ofilename, defaultfilename);
	}

	// read the messages in from a txt file
	






}
