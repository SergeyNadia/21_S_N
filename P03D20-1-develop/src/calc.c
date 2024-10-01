#include "calc.h"

double count(char *output_str, HEAD *head, double x) {
    int n = strlen(output_str);
    double num1, num2;
    for (int i = 0; i < n; ++i) {
        if (output_str[i] == 'x') {
            add_sym(x, head);
        } else if (output_str[i] >= '0' && output_str[i] <= '9') {
            add_sym((output_str[i] - '0'), head);
        } else if (output_str[i] == '+') {
            num2 = pop(head);
            num1 = pop(head);
            add_sym(num1 + num2, head);
        } else if (output_str[i] == '-') {
            num2 = pop(head);
            num1 = pop(head);
            add_sym(num1 - num2, head);
        } else if (output_str[i] == '*') {
            num2 = pop(head);
            num1 = pop(head);
            add_sym(num1 * num2, head);
        } else if (output_str[i] == '/') {
            num2 = pop(head);
            num1 = pop(head);
            if (num2 != 0)
                add_sym(num1 / num2, head);
            else
                add_sym(1000, head);
        } else if (output_str[i] == 's') {
            num1 = pop(head);
            add_sym(sin(num1), head);
        } else if (output_str[i] == 'c') {
            num1 = pop(head);
            add_sym(cos(num1), head);
        } else if (output_str[i] == 't') {
            num1 = pop(head);
            add_sym(tan(num1), head);
        } else if (output_str[i] == 'g') {
            num1 = pop(head);
            add_sym(1 / tan(num1), head);
        } else if (output_str[i] == 'q') {
            num1 = pop(head);
            add_sym(sqrt(num1), head);
        } else if (output_str[i] == 'l') {
            num1 = pop(head);
            add_sym(log(num1), head);
        }
    }
    return pop(head);
}

void init(HEAD *head) { head->point = NULL; }

void add_sym(double sym, HEAD *head) {
    OPERATIONS *tmp;
    tmp = head->point;
    OPERATIONS *new = (OPERATIONS *)malloc(sizeof(OPERATIONS));
    new->oper = sym;
    new->point = tmp;
    head->point = new;
}

double pop(HEAD *head) {
    double x;
    OPERATIONS *tmp = head->point;
    x = head->point->oper;
    head->point = head->point->point;
    free(tmp);
    return x;
}

void calc_graph(char **graph, int width, char *out, HEAD *head) {
    for (int x = 0; x < width; x++) {
        int local_y = 25;
        if (x != 0) local_y = round(12 + 12 * count(out, head, (M_PI * x) / 20));
        if (local_y > 0 && local_y < 25) graph[local_y][x] = STAR;
    }
}
