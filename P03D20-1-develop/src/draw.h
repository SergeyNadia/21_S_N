#ifndef GRAPH_H_
#define GRAPH_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#define WIDTH 80
#define HEIGHT 25
#define POINT '.'
#define STAR '*'

char **allc_matrix(int height, int width);
void init_graph(char **graph, int height, int width);
void draw_graph(char **graph, int height);
void free_matrix(char **graph, int height);

#endif  // GRAPH_H_