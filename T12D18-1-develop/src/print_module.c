#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char *message) {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    // Буфер для хранения строки времени
    char time_buffer[9];  // Формат ЧЧ:ММ:СС, 8 символов + 1 для '\0'
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", local_time);

    // Вывод префикса [LOG]
    char log_prefix[] = Log_prefix " ";
    for (int i = 0; log_prefix[i] != '\0'; i++) {
        print(log_prefix[i]);
    }

    // Вывод времени
    for (int i = 0; time_buffer[i] != '\0'; i++) {
        print(time_buffer[i]);
    }

    // Вывод пробела и сообщения
    print(' ');
    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }

    // Завершаем вывод новой строкой
    print('\n');
}
