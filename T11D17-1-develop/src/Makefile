CC=gcc
GFLAGS=-Wall -Werror -Wextra
BUILD=../build/

door_struct: dmanager_module.o 
	$(CC) $(CFLAGS) dmanager_module.o -o $(BUILD)Quest_1

list_test: list_test.o list.o
	$(CC) $(GFLAGS) list_test.o list.o -o $(BUILD)Quest_2

stack_test: stack_test.o stack.o
	$(CC) $(GFLAGS) stack_test.o stack.o -o $(BUILD)Quest_3

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) dmanager_module.c -c

list_test.o: list_test.c
	$(CC) $(CFLAGS) list_test.c -c

list.o: list.c
	$(CC) $(CFLAGS) list.c -c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c -c

stack_test.o: stack_test.c
	$(CC) $(CFLAGS) stack_test.c -c

clean:
	rm -rf *.o $(BUILD)Quest_1 $(BUILD)Quest_2 $(BUILD)Quest_3

rebuild_quest1: clean door_struct

rebuild_quest2: clean list_test
