#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <stdio.h>
#include <stdlib.h>

struct st {
    char c;
    struct st *next;
};
struct st *push(struct st *, char);
char delete (struct st **);
int priority(char);
void parse(struct st *operations, char *input_str, char *output_str);

#endif  // MYSTACK_H_