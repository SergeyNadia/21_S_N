#ifndef STACK_H
#define STACK_H

typedef struct {
    int* data;
    int size;
    int capacity;
} Stack;

Stack* init(int capacity);
void push(Stack* s, int item);
int pop(Stack* s);
void destroy(Stack* s);

// Добавляем объявление функции
int stack_size(Stack* s);

#endif  // STACK_H
