#ifndef LIST_H
#define LIST_H

typedef struct {
    int id;
} Door;

typedef struct Node {
    Door *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

List *init(List *list, Door *door);
List *add_door(List *elem, Door *door);
Node *remove_door(Node *elem, Node *root);

void free_list(List *list);

#endif
