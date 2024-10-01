#ifndef CALCULATION_H_
#define CALCULATION_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"

typedef struct OPERATIONS {
    double oper;
    struct OPERATIONS *point;
} OPERATIONS;

typedef struct HEAD {
    struct OPERATIONS *point;
} HEAD;

double count(char *output_str, HEAD *head, double x);
void init(HEAD *head);
void add_sym(double sym, HEAD *head);
double pop(HEAD *head);
void calc_graph(char **graph, int width, char *out, HEAD *head);

#endif