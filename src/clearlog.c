#include <stdlib.h>
#include "../log.h"

// log_t* headptr and log_t* tailptr defined in log.c
extern log_t* headptr;
extern log_t* tailptr;

// clearlog function
// release all the storage that has been allocated for the logged msg and
// empty the list of logged msgs
void clearlog(void) {
	log_t* currentnode = headptr;
	log_t* nextnode;

	// traverse the list, deleting each node & releasing memory
	while (currentnode != NULL) {
		nextnode = currentnode->next;
		free(currentnode); // deallocate memory
		currentnode = nextnode;
	}
	
	headptr = NULL;
}
