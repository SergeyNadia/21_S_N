#include <math.h>
#include <stdio.h>

int main() {
    char number[50];
    scanf("%s", number);
    double x = 0;
    if (sscanf(number, "%lf", &x) == 1) {  // Используем sscanf для чтения числа из строки
        double y = 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1000) * x + 3) / (x * x / 2) -
                   x * pow((10 + x), 2 / x) - 1.01;
        printf("%.1f\n", y);
    } else {
        printf("n/a\n");
    }
    return 0;
}