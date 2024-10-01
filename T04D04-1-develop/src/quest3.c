#include <stdio.h>

int fib(int n, int depth) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int res = fib(n - 1, depth + 4) + fib(n - 2, depth + 4);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n - 1, 1));
    return 0;
}