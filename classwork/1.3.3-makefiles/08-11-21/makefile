all: generate

echo.o: echo.c
	gcc -c -Wall -Wextra echo.c

main.o: main.c
	gcc -c -Wall -Wextra main.c

generate: main.o echo.o
	gcc main.o echo.o

clean:
	rm -f *.o a.out