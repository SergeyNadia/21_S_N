CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

build: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: s21_string.o s21_string_test_quest1.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_1

strcmp_tests: s21_string.o s21_string_test_quest2.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_2

strcpy_tests: s21_string.o s21_string_test_quest3.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_3

strcat_tests: s21_string.o s21_string_test_quest4.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_4

strchr_tests: s21_string.o s21_string_test_quest5.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_5

strstr_tests: s21_string.o s21_string_test_quest6.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_6

strtok_tests: s21_string.o s21_string_test_quest7.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_7

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c -c

s21_string_test_quest1.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQUEST1 s21_string_test.c -c

s21_string_test_quest2.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST2 s21_string_test.c -c

s21_string_test_quest3.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST3 s21_string_test.c -c

s21_string_test_quest4.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST4 s21_string_test.c -c

s21_string_test_quest5.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST5 s21_string_test.c -c

s21_string_test_quest6.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST6 s21_string_test.c -c

s21_string_test_quest7.o: s21_string_test.c 
	$(CC) $(CFLAGS) -DQUEST7 s21_string_test.c -c

clean:
	rm -rf *.o $(BUILD)Quest_1 $(BUILD)Quest_2 $(BUILD)Quest_3 $(BUILD)Quest_4 $(BUILD)Quest_5 $(BUILD)Quest_6 $(BUILD)Quest_7 *.a *.so

rebuild_quest1: clean strlen_tests

rebuild_quest2: clean strcmp_tests

rebuild_quest3: clean strcpy_tests

rebuild_quest4: clean strcat_tests

rebuild_quest5: clean strchr_tests

rebuild_quest6: clean strstr_tests

rebuild_quest7: clean strtok_tests