#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 10000

void initialize_doors(door *doors);
void sort_and_print_doors(door *doors);

int main() {
    door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_and_print_doors(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_and_print_doors(door *doors) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < DOORS_COUNT - 1; i++) {
            if (doors[i].id > doors[i + 1].id) {
                door temp = doors[i];
                doors[i] = doors[i + 1];
                doors[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);

    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }

    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
    printf("%d, %d\n", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT - 1].status);
}