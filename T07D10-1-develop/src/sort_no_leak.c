#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int *input(int *a, int *length, int *check);
void output(int *a, int *check, int *length);
void sort(int *a, int *length);

int main() {
    int *data = 0;
    int length = 0, check = 0;
    data = input(data, &length, &check);
    sort(data, &length);
    output(data, &check, &length);
    free(data);
}

int *input(int *a, int *length, int *check) {
    if (scanf("%d", length) != 1 && getchar() != '\n') {
        *check = 0;
    } else {
        a = malloc((*length) * sizeof(int));
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", &a[i]) != 1) {
                *check = 0;
            } else {
                *check = 1;
            }
        }
    }
    return a;
}

void sort(int *a, int *length) {
    int buf;
    for (int i = 0; i < *length; i++) {
        for (int j = i + 1; j < *length + 1; j++) {
            if (a[i] > a[j]) {
                buf = a[i];
                a[i] = a[j];
                a[j] = buf;
            }
        }
    }
}

void output(int *a, int *check, int *length) {
    if (*check == 0) {
        printf("n/a");
    } else {
        for (int i = 1; i < *length + 1; i++) {
            printf("%d", a[i]);
            if (i != *length) {
                printf(" ");
            }
        }
    }
}
