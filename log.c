#include <stdio.h>
#include <string.h>
#include <time.h>
#include "log.h"

log_t* headptr = NULL;
log_t* tailptr = NULL;

// writenode function
// helper function that returns a string containing the contents of a single node
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
