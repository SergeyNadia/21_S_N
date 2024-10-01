#include "bst.h"

#include <stdlib.h>

// Функция создания нового узла дерева
t_btree *bstree_create_node(int item) {
    t_btree *new_node = (t_btree *)malloc(sizeof(t_btree));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Функция для освобождения памяти узла дерева
void bstree_free_node(t_btree *node) {
    if (node != NULL) {
        free(node);
    }
}
