CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11
EXNAME=ex3

all: generate

$(EXNAME).o: $(EXNAME).c
	$(CC) -c $(CFLAGS) $(EXNAME).c

generate: $(EXNAME).o
	$(CC) $(CFLAGS) $(EXNAME).o -o $(EXNAME).out

clean: 
	rm -f *.o *.out