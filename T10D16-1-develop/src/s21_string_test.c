#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
#ifdef QUEST1
    if (s21_strlen("test_out") == 8) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strlen("super_star") == 10) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strlen("") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
#endif

#ifdef QUEST2
    if (s21_strcmp("cheak_out", "cheak_out") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strcmp("aboba", "ab0ba") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strcmp("s1", "sI") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
#endif

#ifdef QUEST3
    char str1[] = "Hello!";
    char str2[] = "World)";
    char str3[] = "Peace!";
    s21_strcpy(str1, str2);
    if (s21_strlen(str1) == s21_strlen(str2)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    s21_strcpy(str3, str1);
    if (s21_strlen(str3) == s21_strlen(str1)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    s21_strcpy(str2, str3);
    if (s21_strlen(str2) == s21_strlen(str3)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
#endif

#ifdef QUEST4
    char s[100] = "rain_";
    s21_strcat(s, "couper_rian");
    if (s21_strlen(s) == 12) {
        printf(" SUCCESS");
    } else {
        printf(" FAIL");
    }
    printf("\n");

    char s1[3] = "Cat";
    if (s21_strlen(s21_strcat(s1, "\0")) == 4) {
        printf(" SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");

    char s2[1] = "";
    if (s21_strlen(s2) == 1) {
        printf(" SUCCESS");
    } else {
        printf(" FAIL");
    }
#endif

#ifdef QUEST5
    char s[7] = "Ponts";
    char *r = s21_strchr(s, 's');
    if (r != NULL && *r == 's') {
        printf(" SUCCESS");
    } else {
        printf(" FAIL");
    }
    printf("\n");

    char s1[4] = "CAR";

    char *r2 = s21_strchr(s1, 'A');
    if (r != NULL && *r2 == '\0') {
        printf(" SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");

    char s2[2] = "";
    char *r3 = s21_strchr(s2, ' ');
    if (r != NULL && *r3 == ' ') {
        printf(" SUCCESS");
    } else {
        printf(" FAIL");
    }
#endif

#ifdef QUEST6
    char s[10] = "Mafusail!";

    char *r = s21_strstr(s, "sail");
    if (r != NULL && s21_strcmp(r, "sail") == 0) {
        printf(" SUCCESS\n");
    } else {
        printf(" FAIL\n");
    }

    char s1[8] = "Bipolar";

    char *r2 = s21_strstr(s1, "lar");
    if (r2 != NULL && s21_strcmp(r2, "lar") == 0) {
        printf(" SUCCESS\n");
    } else {
        printf(" FAIL\n");
    }

    char s2[2] = "";

    char *r3 = s21_strstr(s2, " ");
    if (r3 != NULL && s21_strcmp(r3, " ") == 0) {
        printf(" SUCCESS\n");
    } else {
        printf(" FAIL\n");
    }

#endif

#ifdef QUEST7
    if (s21_strtok("Hello world", "Hello")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strtok("super_star", "super")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    if (s21_strtok("", "")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
#endif
    return 0;
}