CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

all: state_sort state_search clear_state

state_sort: state_sort.o 
	$(CC) $(CFLAGS) state_sort.o -o $(BUILD)Quest_1
	rm -rf state_sort.o

state_search: state_search.o
	$(CC) $(CFLAGS)  state_search.o -o $(BUILD)Quest_2
	rm -rf state_search.o

clear_state: clear_state.o
	$(CC) $(CFLAGS)  clear_state.o -o $(BUILD)Quest_3
	rm -rf clear_state.o

state_sort.o: state_sort.c 
	$(CC) $(CFLAGS) state_sort.c -c

state_search.o: state_search.c
	$(CC) $(CFLAGS) state_search.c -c

clear_state.o: clear_state.c
	$(CC) $(CFLAGS) clear_state.c -c

clean:
	rm -rf *.o $(BUILD)Quest_1 $(BUILD)Quest_2 $(BUILD)Quest_3

rebuild: clean all