#include <time.h>

typedef struct data_struct
{
	time_t time;
	char type;
	char* string;
} data_t;

int addmsg(const char type, const char* msg); // create a new instance of the struct and copy it to the end of the list
void clearlog(); // release storage allocated for the msg and empty the list of logged msgs
char* getlog(); // create a st containing the entire log amd return a ptr to the str
int savelog(char* filename); // save the logged msg to a disk file

