#include "node.h"
#include <stdlib.h> // for malloc and free
#include <assert.h> // for assert
#include <stdio.h> // for printf

struct nodeStruct {
	int payload;
	node next;
};

node node_create(int payload) {
	node nde = malloc(sizeof(struct nodeStruct));
	nde->payload = payload;
	nde->next=NULL;
	return nde;
}

bool node_hasNext(node nde) {
	assert(nde!=NULL);
	return (nde->next!=NULL);
}

node node_getNext(node nde) {
	assert(nde!=NULL);
	return nde->next;
}

void node_setNext(node from, node to) {
	assert(from!=NULL);
	from->next=to;
}

int node_getPayload(node nde) {
	assert(nde!=NULL);
	return nde->payload;
}

void node_print(node nde) {
	assert(nde!=NULL);
	printf("%d",nde->payload);
	if (nde->next) printf("->");
}

void node_free(node nde) {
	assert(nde!=NULL);
	if (nde->next) node_free(nde->next);
	nde->next=NULL; // In case we ever get back here
	free(nde);
}