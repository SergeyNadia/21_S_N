#include <stdio.h>

#define N 10

int input(int* arr);
void sort_array(int* arr, int size);
void output(const int* arr);

int main() {
    int mass[N];
    if (input(mass) != 0) {
        sort_array(mass, N);
        output(mass);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int* arr) {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }
    return *arr;
}

void sort_array(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void output(const int* arr) {
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[N - 1]);
}
