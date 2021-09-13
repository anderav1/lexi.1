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

log_t* gethead();
void sethead(log_t* ptr);
log_t* gettail();
void settail(log_t* ptr);

int addmsg(const char type, const char* msg);
void clearlog();
char* getlog();
int savelog(char* filename);
char* nodestring(log_t* node);

#endif

