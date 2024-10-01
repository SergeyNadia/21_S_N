#include "stack.h"

#include <stdlib.h>

Stack* init(int capacity) {
    Stack* s = malloc(sizeof(Stack));
    if (!s) {
        return NULL;
    }
    s->data = malloc(sizeof(int) * capacity);
    if (!s->data) {
        free(s);
        return NULL;
    }
    s->size = 0;
    s->capacity = capacity;
    return s;
}

void push(Stack* s, int item) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[s->size++] = item;
}

int pop(Stack* s) {
    if (s->size == 0) {
        return -1;
    }

    int item = s->data[--s->size];

    // Если стек не пустой после извлечения элемента, уменьшаем его размер
    if (s->size > 0) {
        s->capacity /= 2;
        s->data = realloc(s->data, sizeof(int) * s->capacity);
    }

    return item;
}

int stack_size(Stack* s) { return s->size; }

void destroy(Stack* s) {
    free(s->data);
    free(s);
}
