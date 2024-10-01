#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return length;
}

int s21_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 < *s2) ? -1 : 1;
        }
        s1++;
        s2++;
    }

    if (*s1 != '\0' && *s2 != '\0') {
        return (*s1 < *s2) ? -1 : 1;
    }

    return 0;
}

char *s21_strcpy(char *dest, const char *src) {
    char *temp = dest;
    while ((*temp++ = *src++) != '\0')
        ;
    return dest;
}

char *s21_strcat(char *s, char *v) {
    while (*s) {
        s++;
    }
    while (*v) {
        *s = *v;
        s++;
        v++;
    }
    *s = '\0';
    return s;
}

char *s21_strchr(char *str, int ch) {
    char *res = str;

    while (*res != '\0') {
        if (*res == (char)ch) {
            return res;
        }
        res++;
    }

    return NULL;
}

char *s21_strstr(char *strB, char *strA) {
    if (*strA == '\0') {
        return (char *)strB;
    }

    while (*strB) {
        char *b = strB;
        char *a = strA;

        while (*a && (*b == *a)) {
            b++;
            a++;
        }

        if (*a == '\0') {
            return (char *)strB;
        }

        strB++;
    }

    return NULL;
}

char *s21_strtok(char *str, char *sep) {
    static char *last;
    if (str == NULL) {
        str = last;
    }

    if (str == NULL) return NULL;

    while (*str && s21_strchr(sep, *str)) {
        str++;
    }

    if (*str == '\0') return NULL;

    char *token_start = str;

    while (*str && !s21_strchr(sep, *str)) {
        str++;
    }

    if (*str) {
        *str = '\0';
        last = str + 1;
    } else {
        last = NULL;
    }

    return token_start;
}