CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11 -lm
MTARGET=main
ETARGET=linkedlist
ONAME=ex2

all: generate

$(ETARGET).o: $(ETARGET).c
	$(CC) -c $(CFLAGS) $(ETARGET).c

$(MTARGET).o: $(MTARGET).c
	$(CC) -c $(CFLAGS) $(MTARGET).c

generate: $(MTARGET).o $(ETARGET).o
	$(CC) $(CFLAGS) $(MTARGET).o $(ETARGET).o -o $(ONAME).out

clean: 
	rm -f *.o *.out