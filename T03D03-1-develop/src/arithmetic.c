#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
void div(int a, int b);

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if (a == (int)a && b == (int)b) {
        printf("%d %d %d ", sum(a, b), sub(a, b), mult(a, b));
        div(a, b);
    } else {
        printf("n/a\n");
    }
    return 0;
}

int sum(int a, int b) { return (a + b); }

int sub(int a, int b) { return (a - b); }

int mult(int a, int b) { return (a * b); }

void div(int a, int b) {
    if (b != 0) {
        printf("%d\n", a / b);
    } else {
        printf("n/a\n");
    }
}