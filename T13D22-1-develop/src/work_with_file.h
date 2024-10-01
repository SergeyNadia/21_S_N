#ifndef WORK_WITH_FILE_H_
#define WORK_WITH_FILE_H_
#include <stdio.h>
#define SIZE 255

int read_file(FILE *file, char *path);
int write_in_file(FILE *file, char *path);
void caesar_cipher(const char *input_file, const char *output_file, int shift);
void des_encrypt(const char *directory);

#endif  // WORK_WITH_FILE_H_