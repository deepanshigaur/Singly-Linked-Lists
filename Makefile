CC = gcc
CFLAGS = -Wall -std=c18 -ggdb

test : tryList
	./tryList 12 45 10 21 32 12 61
	
gdb : tryList
	gdb --args ./tryList 12 45 10 21 32 12 61
	
checkMem : tryGeom
	valgrind --leak-check=full --show-leak-kinds=all ./tryList 12 45 10 21 32 12 61	
	
tryList : tryList.c node.c node.h list.c list.h
	${CC} ${CFLAGS} -o tryList tryList.c node.c list.c

clean: 
	-rm tryList 