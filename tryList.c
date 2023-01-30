#include "list.h"
#include <stdlib.h> // for atoi

int main(int argc, char **argv) {

	list list1=list_create();
	list list2=list_create();
	list list3=list_create();

	for(int i=1;i<argc;i++) {
		int n=atoi(argv[i]);
		list_insertStart(list1,node_create(n));
		list_insertEnd(list2,node_create(n));
		list_insertOrder(list3,node_create(n));
	}

	list_print("list1: ",list1);
	list_print("list2: ",list2);
	list_print("list3: ",list3);

	list_free(list1);
	list_free(list2);
	list_free(list3);
	return 0;
}
