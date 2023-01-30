#ifndef NODE_H
#define NODE_H
#include <stdbool.h> // For boolean return value

// A node is just a pointer to an instance of the node structure
typedef struct nodeStruct* node;

// What can we do with nodes?
node node_create(int payload);
bool node_hasNext(node nde);
node node_getNext(node nde);
void node_setNext(node from, node to);
int node_getPayload(node nde);
void node_print(node nde);
void node_free(node nde);

#endif