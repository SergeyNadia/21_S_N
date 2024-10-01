#include <stdio.h>

#include "bst.h"

void test_bstree_create_node(int item) {
    t_btree *node = bstree_create_node(item);

    if (node != NULL) {
        printf("Node created with item: %d\n", node->item);
        printf("Left child: %p, Right child: %p\n", (void *)node->left, (void *)node->right);
        bstree_free_node(node);  // Освобождаем память узла после использования
    } else {
        printf("Failed to create node with item: %d\n", item);
    }
}

int main() {
    // Тестируем создание узлов с разными значениями
    test_bstree_create_node(5);
    test_bstree_create_node(10);

    return 0;
}
