#include <math.h>
#include <stdio.h>

int minn(int number);

int main() {
    int number;
    int y;
    int maxis = 0;
    scanf("%d", &number);
    if (number < 0) number = number * -1;
    int x = number;
    for (int i = 2; i < x; i++) {
        y = number;
        if (minn(i)) {
            while (y > 0) {
                y -= i;
            }
            if (y == 0) maxis = i;
        }
    }
    if (maxis != 0 && maxis != 1)
        printf("%d\n", maxis);
    else
        printf("n/a\n");
    return 0;
}

int minn(int number) {
    int a = number / 2;
    int y;
    for (int i = 2; i <= a; i++) {
        y = number;
        while (y > 0) {
            y -= i;
        };
        if (y == 0) return 0;
    }
    return 1;
}