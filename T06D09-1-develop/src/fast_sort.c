#include <stdio.h>

#define N 10

int input(int* arr);
void sort_array(int* arr, int size);
void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

void output(const int* arr);

int main() {
    int mass[N];
    if (input(mass) != 0) {
        sort_array(mass, N);
        output(mass);
        printf("\n");
        merge_sort(mass, 0, N - 1);
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

void merge_sort(int* arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    static int temp1[N];
    static int temp2[N];

    for (int i = 0; i < n1; i++) temp1[i] = arr[left + i];
    for (int j = 0; j < n2; j++) temp2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            arr[k++] = temp1[i++];
        } else {
            arr[k++] = temp2[j++];
        }
    }

    while (i < n1) arr[k++] = temp1[i++];
    while (j < n2) arr[k++] = temp2[j++];
}

void output(const int* arr) {
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[N - 1]);
}
