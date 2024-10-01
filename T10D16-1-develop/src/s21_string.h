#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

s21_size_t s21_strlen(const char *str);
int s21_strcmp(const char *s1, const char *s2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *s, char *v);
char *s21_strchr(char *str, int ch);
char *s21_strstr(char *strB, char *strA);
char *s21_strtok(char *str, char *sep);

#endif