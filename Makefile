# Comment


CC=gcc
CFLAGS=-Wall -Werror -g
BINS=testReadData

all: $(BINS)

testReadData : testReadData.o readData.o graph.o list.o
	$(CC) -o testReadData testReadData.o readData.o graph.o list.o

list.o : list.c list.h

graph.o : graph.c graph.h list.h

readData.o : readData.c readData.h graph.h list.h

testReadData.o : testReadData.c readData.h graph.h list.h

clean :
	rm -f $(BINS) *.o core
