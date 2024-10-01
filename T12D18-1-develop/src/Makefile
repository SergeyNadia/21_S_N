CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD_DIR = ../build
EXEC1 = $(BUILD_DIR)/Quest_1
EXEC2 = $(BUILD_DIR)/Quest_2
EXEC3 = $(BUILD_DIR)/Quest_3

SRC_FILES = main_module_entry_point.c print_module.c
SRC_FILES2 = main_module_entry_point.c documentation_module.c print_module.c
SRC_FILES3 = bst_create_test.c bst.c
OBJ_FILES = main_module_entry_point.o print_module.o
OBJ_FILES2 = main_module_entry_point.o documentation_module.o print_module.o
OBJ_FILES3 = bst_create_test.o bst.o

all: print_module documentation_module bst_create_test

print_module: $(SRC_FILES) $(OBJ_FILES)
	@$(CC) $(CFLAGS) -c $(SRC_FILES)
	@$(CC) $(CFLAGS) -o $(EXEC1) $(OBJ_FILES)
	@rm -rf *.o

documentation_module: CFLAGS += -DDOC
documentation_module: $(SRC_FILES2) $(OBJ_FILES2)
	@$(CC) $(CFLAGS) -c $(SRC_FILES2)
	@$(CC) $(CFLAGS) -o $(EXEC2) $(OBJ_FILES2)
	@rm -rf *.o

bst_create_test: $(SRC_FILES3) $(OBJ_FILES3)
	@$(CC) $(CFLAGS) -c $(SRC_FILES3)
	@$(CC) $(CFLAGS) -o $(EXEC3) $(OBJ_FILES3)
	@rm -rf *.o

clean:
	@rm -rf $(EXEC1) $(EXEC2) $(EXEC3)

rebuild_print_module: clean all
