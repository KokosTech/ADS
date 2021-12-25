CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11 -lm
TARGET=main

all: generate

hash_table.o: hash_table.c
	$(CC) -c $(CFLAGS) hash_table.c

dynamic.o: dynamic.c
	$(CC) -c $(CFLAGS) dynamic.c

$(TARGET).o: $(TARGET).c
	$(CC) -c $(CFLAGS) $(TARGET).c

generate: $(TARGET).o dynamic.o hash_table.o
	$(CC) $(CFLAGS) $(TARGET).o dynamic.o hash_table.o -o $(TARGET).out

clean: 
	rm -f *.o *.out