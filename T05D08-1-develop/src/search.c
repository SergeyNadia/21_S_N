#include <math.h>
#include <stdio.h>

#define MAX_SIZE 30

// Функция чтения массива из stdin
int* read_array(int size) {
    static int arr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("n/a");
            return 0;
        }
    }
    return arr;
}

// Функция расчета математического ожидания
double calculate_mean(int* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Функция расчета дисперсии (варьянса)
double calculate_variance(int* arr, int size) {
    double mean = calculate_mean(arr, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sum / size;
}

// Функция проверки условия четности
int is_even(int num) { return num % 2 == 0; }

// Функция проверки условия сравнения с математическим ожиданием
int is_greater_than_or_equal_to_mean(double mean, int num) { return num >= mean; }

// Функция проверки условия трех сигм
int is_three_sigma(double variance, double mean, int num) {
    double three_sigma = 3 * sqrt(variance);
    return num <= mean + three_sigma;
}

// Функция проверки условия неравенства с нулем
int is_not_zero(int num) { return num != 0; }

// Основная функция для поиска и вывода результата
void find_and_print_result(int* arr, int size) {
    double mean = calculate_mean(arr, size);
    double variance = calculate_variance(arr, size);

    for (int i = 0; i < size; i++) {
        if (is_even(arr[i]) && is_greater_than_or_equal_to_mean(mean, arr[i]) &&
            is_three_sigma(variance, mean, arr[i]) && is_not_zero(arr[i])) {
            printf("%d", arr[i]);
            break;  // Прекращаем цикл после нахождения первого подходящего числа
        }
    }

    // Если ни одно число не удовлетворяет условиям, выводим n/a
    if (size > 0 && !arr[0]) {
        printf("n/a");
    }
}

int main() {
    int size;
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("n/a");
        return 0;
    }

    int* arr = read_array(size);
    if (arr == NULL) {
        return 0;
    }
    find_and_print_result(arr, size);

    // Освобождаем память, если она была выделена динамически

    return 0;
}
