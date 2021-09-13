# Project 1: Linux System Calls
Lexi Anderson, CS 4760

## C Static Library Functions
I implemented the following required functions in my static library liblog.a:

```c
int addmsg(const char type, const char* msg);
void clearlog();
char* getlog();
int savelog(char* filename);
```

I also included in my library a helper function, nodestring, that would produce a string containing the info for a single log item, as well as pointers to the head and the tail of the list.

Each of the required functions is defined in a separate C file. I created an additional log.c file in which I defined the nodestring function and the pointers.

## getlog.c String Allocation
I didn't want to spend too much time dwelling on how to calculate the amount of memory needed to store the entire log, so I just hard-coded a high value.

## Makefile
I had trouble trying to figure out how to organize the Makefile, especially since I have never dealt with linking a static library before. I spent a lot of hours researching how to make this work.

 
