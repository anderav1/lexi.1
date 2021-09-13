#ifndef LOG_H
#define LOG_H

#include <time.h>

typedef struct data_struct
{
	time_t time;
	char type;
	char* string;
} data_t;

typedef struct list_struct
{
	data_t item;
	struct list_struct* next;
} log_t;

extern log_t* headptr;
extern log_t* tailptr;

int addmsg(const char type, const char* msg);
void clearlog();
char* getlog();
int savelog(char* filename);
char* nodestring(log_t* node);

#endif

