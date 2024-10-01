#include "documentation_module.h"

#include <stdlib.h>

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    int *availability = (int *)malloc(document_count * sizeof(int));
    if (availability == NULL) {
        return NULL;
    }

    // Инициализация списка переменных аргументов
    va_list args;
    va_start(args, document_count);

    // Применение функции validate к каждому документу
    for (int i = 0; i < document_count; i++) {
        char *document = va_arg(args, char *);
        availability[i] = validate(document);  // Заполняем массив результатами валидации
    }

    va_end(args);
    return availability;
}
