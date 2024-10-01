CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
BUILD = ../build/

all: graph

graph: stack.o parse.o calc.o draw.o graph.o
	$(CC) $(CFLAGS) stack.o graph.o parse.o draw.o calc.o -o $(BUILD)graph

calc.o: calc.c calc.h
	$(CC) $(CFLAGS)	calc.c -c

draw.o:
	$(CC) $(CFLAGS)	draw.c -c

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c -c

parse.o: parse.c
	$(CC) $(CFLAGS) parse.c -c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c -c

clean:
	rm -rf *.o $(BUILD)graph

rebuild: clean all