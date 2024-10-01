#include <stdio.h>

double maxx(double a, double b);

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if (a == (int)a && b == (int)b) {
        printf("%.0lf\n", maxx(a, b));
    } else {
        printf("n/a\n");
    }
    return 0;
}

double maxx(double a, double b) { return a > b ? a : b; }