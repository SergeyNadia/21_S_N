#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    squaring(data, &n);
    output(data, &n);

    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n <= 0 || *n != (short int)*n) {
        printf("n/a");
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return *n;
}

void output(int *a, int *n) {
    int temp = 0;
    for (int *p = a; p - a < *n; p++) {
        if (*p >= 1000000) {
            temp++;
        }
    }
    for (int *p = a; p - a < *n; p++) {
        if (temp != 0 || *n != (short int)*n) {
            printf("n/a");
            break;
        } else {
            if (*n - 1 > p - a) {
                printf("%d ", *p);
            } else {
                printf("%d", *p);
            }
        }
    }
}

void squaring(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) *p *= *p;
}
