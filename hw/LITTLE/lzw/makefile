CC=gcc
CFLAGS=-Wall -Wextra --pedantic --std=c11
TARGET=main
LIB0=map
LIB1=lzw

all: generate

$(LIB0).o: $(LIB0).c
	$(CC) -c $(CFLAGS) $(LIB0).c

$(LIB1).o: $(LIB1).c
	$(CC) -c $(CFLAGS) $(LIB1).c

$(TARGET).o: $(TARGET).c
	$(CC) -c $(CFLAGS) $(TARGET).c

generate: $(TARGET).o $(LIB0).o $(LIB1).o
	$(CC) $(CFLAGS) $(TARGET).o $(LIB0).o $(LIB1).o -o $(TARGET).out

clean: 
	rm -f *.o *.out