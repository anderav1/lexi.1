#include "log.h"

// addmsg function
// create a new data_t struct and insert it at the end of the log list
int addmsg(const char type, const char* msg) {
	// get current time
	time_t tm;
	time(&tm);
	struct tm* tp = localtime(&tm);
	
	// create a new node

	// create a new data_t struct
	data_t msgstruct;
	msgstruct.time = tm;
	msgstruct.type = type;
	msgstruct.string = msg;

	// format time
	char* timestring;
	sprintf(timestring, "%.2d:%.2d:%.2d\n", tp->tm_hour, tp-tm_min, tp->tm_sec);

	// insert the struct at the end of the log list
}
