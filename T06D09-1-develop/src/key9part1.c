/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define N 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int lenght = 10, buffer[N], numbers_found[N];
    input(buffer, &lenght);

    if (lenght <= 10 && lenght > 0) {
        int sum_even = sum_numbers(buffer, lenght);
        if (sum_even == 0 || sum_even > lenght) {
            printf("n/a");
        } else {
            int num_found = find_numbers(buffer, lenght, sum_even, numbers_found);

            printf("%d\n", sum_even);
            output(numbers_found, num_found);
        }
    } else {
        printf("n/a");
    }

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p % 2 == 0 && ((p - buffer) % 2) == 0) {
            sum += *p;
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int sum, int *new_buffer) {
    int *i = new_buffer;
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && sum % *p == 0) {
            *(i + count) = *p;
            count++;
        }
    }
    return count;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) == 1) {
        for (int i = 0; i < *length; i++) {
            scanf("%d", &buffer[i]);
        }
    }
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length) printf(" ");
    }
}