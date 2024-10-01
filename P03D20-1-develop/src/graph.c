#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "draw.h"
#include "stack.h"

int main() {
    char **graph = allc_matrix(HEIGHT, WIDTH + 1);
    struct st *operations = NULL;
    char input_string[80], output_string[80];
    fgets(input_string, 80, stdin);
    parse(operations, input_string, output_string);
    printf("\n%s\n", output_string);
    HEAD head;
    init(&head);
    init_graph(graph, HEIGHT, WIDTH);
    calc_graph(graph, WIDTH, output_string, &head);
    draw_graph(graph, HEIGHT);
    free_matrix(graph, HEIGHT);
    return 0;
}
