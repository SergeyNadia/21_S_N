#include <ctype.h>
#include <stdio.h>

void coding(void) {
    int ch;
    while ((ch = getchar()) != '\n') {
        if (ch != ' ') {
            printf("%02X ", ch);  // Выводим ASCII значение в шестнадцатеричном формате
        } else {
            putchar(' ');  // Выводим пробел
        }
    }
    putchar('\n');
}

void decoding_1(void) {
    int ch;
    while (scanf("%02X", &ch) == 1 && getchar() == ' ') {  // Читаем шестнадцатеричное значение и пробел
        putchar(ch);                                       // Выводим символ
    }
    if (getchar() == '\n') {  // Проверяем, закончил ли ввод символом новой строки
        putchar('\n');  // Выводим символ новой строки, если ввод закончен
    } else {
        printf("n/a\n");  // Выводим "n/a", если ввод не закончен корректно
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Ошибка! Не ввели аргумент или указали больше одного аргумента\n");
        return 0;
    }

    if (argv[1][0] == '0') {
        coding();
    }

    if (argv[1][0] == '1') {
        decoding_1();
    }

    return 0;
}
