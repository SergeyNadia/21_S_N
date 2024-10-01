#include "stack.h"

#include <assert.h>
#include <stdio.h>

#define MAX_SIZE 100

void test_push_pop() {
    Stack* s = init(MAX_SIZE);

    push(s, 1);
    assert(pop(s) == 1);

    push(s, 2);
    assert(pop(s) == 2);

    assert(stack_size(s) == 0);  // Проверяем, что стек пуст

    destroy(s);
}

int main() {
    test_push_pop();
    return 0;
}
