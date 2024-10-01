#include <math.h>
#include <stdio.h>
#define N 50

int main() {
    char x[N], y[N];
    scanf("%s %s", x, y);
    double a = 0;
    double b = 0;
    if (sscanf(x, "%lf", &a) == 1 && sscanf(y, "%lf", &b) == 1) {
        if ((a * a) + (b * b) <= 25) {
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        }
    } else {
        printf("n/a\n");
    }
    return 0;
}