CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11
TARGET=main

all: generate

dynamic.o: dynamic.c
	$(CC) -c $(CFLAGS) dynamic.c

$(TARGET).o: $(TARGET).c
	$(CC) -c $(CFLAGS) $(TARGET).c

generate: $(TARGET).o dynamic.o
	$(CC) $(CFLAGS) $(TARGET).o dynamic.o -o $(TARGET).out

clean: 
	rm -f *.o *.out