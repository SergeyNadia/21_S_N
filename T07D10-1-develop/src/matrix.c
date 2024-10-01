#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void input(int **a, int *length, int *length_2, int *check);
void output(int **a, int *check, int *length, int *length_2);
int variant(int *n, int *check);
int scan(int *length, int *length_2, int *check);
void Stat();
void Dyn_1();
void Dyn_2();
void Dyn_3();
void leaks(int **a, int *length);

int main() {
    int check = 0;
    int n = variant(&n, &check);
}

int variant(int *n, int *check) {
    if (scanf("%d", n) != 1 && getchar() != '\n') {
        *check = 0;
    } else {
        switch (*n) {
            case 1:
                Stat();
                break;
            case 2:
                Dyn_1();
                break;
            case 3:
                Dyn_2();
                break;
            case 4:
                Dyn_3();
                break;
        }
    }
    return *n;
}

void input(int **a, int *length, int *length_2, int *check) {
    for (int i = 0; i < *length; i++) {
        for (int j = 0; j < *length_2; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                *check = 0;
            } else {
                *check = 1;
            }
        }
    }
}

int scan(int *length, int *length_2, int *check) {
    if (scanf("%d %d", length, length_2) != 2 && getchar() != '\n') {
        *check = 0;
    } else {
        *check = 1;
    }
    return *check;
}

void Stat() {
    int data[NMAX][NMAX];
    int *data_2[NMAX];
    int length = 0;
    int length_2 = 0;
    int check = scan(&length, &length_2, &check);
    for (int i = 0; i < length; i++) {
        data_2[i] = data[i];
    }
    input(data_2, &length, &length_2, &check);
    output(data_2, &length, &length_2, &check);
}

void Dyn_1() {
    int length = 0;
    int length_2 = 0;
    int check = scan(&length, &length_2, &check);
    int **data = (int **)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        data[i] = (int *)malloc(length_2 * sizeof(int));
    }
    input(data, &length, &length_2, &check);
    output(data, &length, &length_2, &check);
    leaks(data, &length);
}

void Dyn_2() {
    int length = 0;
    int length_2 = 0;
    int check = scan(&length, &length_2, &check);
    int **data = (int **)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        data[i] = (int *)calloc(length_2, sizeof(int));
    }
    input(data, &length, &length_2, &check);
    output(data, &length, &length_2, &check);
    leaks(data, &length);
}

void Dyn_3() {
    int length = 0;
    int length_2 = 0;
    int check = scan(&length, &length_2, &check);
    int **data = (int **)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        data[i] = (int *)calloc(length_2, sizeof(int));
    }
    input(data, &length, &length_2, &check);
    output(data, &length, &length_2, &check);
    leaks(data, &length);
}

void leaks(int **a, int *length) {
    for (int i = 0; i < *length; i++) {
        free(a[i]);
    }
    free(a);
}

void output(int **a, int *check, int *length, int *length_2) {
    if (*check == 0) {
        printf("n/a");
    } else {
        for (int i = 0; i < *length; i++) {
            for (int j = 0; j < *length_2 + 1; j++) {
                printf("%d", a[i][j]);
                if (j != *length) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}
