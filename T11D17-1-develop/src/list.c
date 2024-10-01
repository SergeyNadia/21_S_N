#include "list.h"

#include <stdio.h>
#include <stdlib.h>

// Функция инициализации списка
List *init(List *list, Door *door) {
    list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }

    list->head = malloc(sizeof(Node));
    if (list->head == NULL) {
        free(list);
        return NULL;
    }

    list->head->data = malloc(sizeof(Door));
    if (list->head->data == NULL) {
        free(list->head);
        free(list);
        return NULL;
    }

    list->head->data->id = door->id;
    list->head->next = NULL;

    return list;
}

// Функция добавления элемента в список
List *add_door(List *elem, Door *door) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = malloc(sizeof(Door));
    if (new_node->data == NULL) {
        free(new_node);
        return NULL;
    }

    new_node->data->id = door->id;
    new_node->next = NULL;

    if (elem == NULL) {
        elem = malloc(sizeof(List));
        if (elem == NULL) {
            free(new_node);
            return NULL;
        }
        elem->head = new_node;
    } else {
        Node *current = elem->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return elem;
}

// Функция удаления узла из списка
Node *remove_door(Node *elem, Node *root) {
    if (root == NULL || root->data == NULL) {
        return root;
    }

    if (root == elem) {
        Node *temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    root->next = remove_door(elem, root->next);

    return root;
}
