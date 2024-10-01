#include "list.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door(void) {
    List *list = NULL;
    Door door1 = {1};
    Door door2 = {2};

    list = init(list, &door1);
    if (list == NULL) {
        return FAIL;
    }

    list = add_door(list, &door2);
    if (list == NULL) {
        return FAIL;
    }

    // Проверка корректности добавленного элемента
    if (list->head->next != NULL && list->head->next->data->id == 2) {
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int test_remove_door(void) {
    List *list = NULL;
    Door door1 = {1};
    Door door2 = {2};

    list = init(list, &door1);
    if (list == NULL) {
        return FAIL;
    }

    list = add_door(list, &door2);
    if (list == NULL) {
        return FAIL;
    }

    list->head = remove_door(list->head, list->head);
    if (list->head == NULL || list->head->next == NULL || list->head->next->data->id != 2) {
        return FAIL;
    }

    return SUCCESS;
}

int main() {
    int test_result;

    test_result = test_add_door();
    printf("%s\n", test_result == SUCCESS ? "SUCCESS" : "FAIL");

    test_result = test_remove_door();
    printf("%s\n", test_result == SUCCESS ? "FAIL" : "SUCCESS");

    return 0;
}
