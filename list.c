#include "list.h"
#include <stddef.h> // for NULL
#include <stdlib.h> // for malloc
#include <stdio.h> // for printf
#include <assert.h> // for assert

list list_create() {
	list lst=malloc(sizeof(node));
	(*lst)=NULL;
	return lst;
}

void list_insertStart(list lst, node insert) {
	node oldHead=(*lst);
	(*lst)=insert;
	node_setNext(insert,oldHead);
}

void list_insertEnd(list lst,node insert) {
	// TODO: insert the "insert" node at the end of the list
	// Algorithm:
	// 		If the list is empty, just set what the list is pointing to to "insert"
	//     Otherwise, run node_setNext(insert,tail) where tail is the tail node of the list
}



void list_insertOrder(list lst,node insert) {
	assert(list_valid(lst)); // Make sure there is no endless loop
	// TODO: insert the "insert" node in payload order, from least at the head to greatest at the tail
	// Algorithm:
	//    If lst is empty, add payload to the start of the list and return
	//    Loop through nodes while node_payload(node) < payload
	//		If node_hasNext(node)
	//			If node_getPayload(node_getNext(node)) >= payload
	//				set next of insert to node_getNext(node) and
	//           set next of node to insert and return
	//        // Get here if node_getPayload(node_getNext(node)) < payload
	//        set node to node_getNext(node) and try again
	//		// Get here if node does not have a next pointer - put insert at the end of the list
	//		node_setNext(node,insert) and return
	//	// Get here if NONE of the nodes are <payload... insert at head and return
}

node list_getTail(list lst) {
	assert(list_valid(lst)); // Ensure no endless loop
	if ((*lst)==NULL) return NULL; // Null list has no tail
	node nde=(*lst);
	while(node_hasNext(nde)) {
		nde=node_getNext(nde);
	}
	return nde;
}

int list_size(list lst) {
	if ((*lst)==NULL) return 0; // Nothing in the list
	int size=1; // at least one node
	node nde=(*lst);
	while(node_hasNext(nde)) {
		size++;
		nde=node_getNext(nde);
		assert(size<1000); // In case there is an endless loop
	}
	return size;
}

bool list_valid(list lst) {
	node *visited=malloc(sizeof(node)*list_size(lst));
	int n=0;
	node nde=(*lst);
	while(nde!=NULL) {
		for(int i=0;i<n;i++) {
			if (visited[i]==nde) {
				free(visited);
				return false; // already visited this node!
			}
		}
		visited[n++]=nde;
		nde=node_getNext(nde);
	}
	free(visited);
	return true;
}

void list_print(char *prefix,list lst) {
	assert(list_valid(lst)); // Ensure no endless loop
	if ((*lst)==NULL) printf("%s<empty>\n",prefix);
	else {
		node nde=*lst;
		printf("%s",prefix);
		while(node_hasNext(nde)) {
			node_print(nde);
			nde=node_getNext(nde);
		}
		node_print(nde);
		putchar('\n');
	}
}

void list_free(list lst) {
	if (*lst) node_free(*lst); // Only free the nodes if the list is not empty
	free(lst);
}