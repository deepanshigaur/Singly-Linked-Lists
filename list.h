#ifndef LIST_H
#define LIST_H
#include "node.h"

typedef node * list; // A list is just a pointer to the head node in the list
	// We could keep both the head and the tail, but that would complicate things... let's keep it simple!

// What can we do with a list?
list list_create();
void list_insertStart(list lst, node insert);
void list_insertEnd(list lst,node insert);
void list_insertOrder(list lst,node insert);
node list_getTail(list lst);
bool list_valid(list lst);
void list_print(char *prefix,list lst);
void list_free(list lst);

#endif