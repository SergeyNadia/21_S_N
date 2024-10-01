#include "draw.h"

char **allc_matrix(int height, int width) {
    char **matrix;
    matrix = (char **)calloc(height, sizeof(char *));
    for (int y = 0; y < height; y++) matrix[y] = (char *)calloc(width, sizeof(char));
    return matrix;
}

void init_graph(char **graph, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            graph[y][x] = POINT;
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        graph[y][width + 1] = '\0';
    }
}

void draw_graph(char **graph, int height) {
    for (int y = height; y > 0; y--) {
        printf("%s\n", graph[y]);
    }
}

void free_matrix(char **graph, int height) {
    for (int y = 0; y < height; y++) free(graph[y]);
    free(graph);
}