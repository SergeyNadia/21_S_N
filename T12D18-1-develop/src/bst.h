#ifndef BST_H
#define BST_H

typedef struct s_btree {
    int item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

// Прототипы функций
t_btree *bstree_create_node(int item);
void bstree_free_node(t_btree *node);  // Функция освобождения узла

#endif  // BST_H
