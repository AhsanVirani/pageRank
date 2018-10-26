# Comment


CC=gcc
CFLAGS=-Wall -Werror -g
BINS=testReadData

all: $(BINS)

testReadData : testReadData.o readData.o invertedIndex.o graph.o BSTree.o list.o
	$(CC) -o testReadData testReadData.o readData.o invertedIndex.o graph.o BSTree.o list.o

list.o : list.c list.h

BSTree.o : BSTree.c BSTree.h list.h

graph.o : graph.c graph.h list.h

invertedIndex.o : invertedIndex.c invertedIndex.h readData.h BSTree.h list.h 

readData.o : readData.c readData.h graph.h BSTree.h list.h

testReadData.o : testReadData.c readData.h invertedIndex.h graph.h BSTree.h list.h

clean :
	rm -f $(BINS) *.o core
