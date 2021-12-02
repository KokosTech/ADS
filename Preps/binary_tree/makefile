CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11
NAME=a.out

all: generate

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

generate: main.o
	$(CC) $(CFLAGS) main.o -o $NAME

clean:
	rm -r * .o a.out