CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11
TARGET=main

all: generate

graph.o: graph.c
	$(CC) -c $(CFLAGS) graph.c

$(TARGET).o: $(TARGET).c
	$(CC) -c $(CFLAGS) $(TARGET).c

generate: $(TARGET).o graph.o
	$(CC) $(CFLAGS) $(TARGET).o graph.o -o $(TARGET).out

clean: 
	rm -f *.o *.out
    
