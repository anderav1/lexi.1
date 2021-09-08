#include <time.h>

typedef struct data_struct
{
	time_t time;
	char type;
	char* string;
} data_t;

int addmsg(const char type, const char* msg); // add a new msg to the end of the list
void clearlog(); // empty the list of logged msgs
char* getlog(); // create a str containing the entire log amd return a ptr to the str
int savelog(char* filename); // save the log to a disk file

