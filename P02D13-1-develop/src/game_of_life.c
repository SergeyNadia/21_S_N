#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25
#define DELAY 100000

/*
    Сделать вывод по матрице вроде такого нужного размера

    +-------------+
    |   *         |
    |             |
    |      *      |
    |     * *     |
    |             |
    |             |
    +-------------+

    В консоли должно выглядеть по лучше
    использовать printw() из ncurses
*/
void renderGame(int** gameField);  //отрисовка поля и клеток

void gameCycle(int** gameField);  //в цикле вызываются все остальные функции необходимые во время игры

int pregameInput(int** gameField);  //ввод начального положения

void ingameInput(double* speed, int* active);  // на a/z изменение скорости на Q выход

void updateField(int** gameField);  //расчет новых пустых/свободных мест

int main() {
    initscr();
    int** gameField = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        gameField[i] = malloc(WIDTH * sizeof(int));
    }

    if (pregameInput(gameField)) {
        resizeterm(HEIGHT + 2, WIDTH + 2);
        noecho();
        curs_set(FALSE);
        nodelay(stdscr, true);

        gameCycle(gameField);
    }
    for (int i = 0; i < HEIGHT; i++) {
        free(gameField[i]);
    }
    free(gameField);
    endwin();
    return 0;
}

void gameCycle(int** gameField) {
    int active = 1;
    double speed = 1.0;
    while (active) {
        clear();
        renderGame(gameField);
        refresh();
        usleep(DELAY / speed);
        updateField(gameField);
        ingameInput(&speed, &active);
    }
    nodelay(stdscr, false);
}

int calcLifes(int** gameField, int i, int j) {
    int count = gameField[i == 0 ? HEIGHT - 1 : i - 1][j == 0 ? WIDTH - 1 : j - 1];
    count += gameField[i == 0 ? HEIGHT - 1 : i - 1][j] + gameField[i + 1 == HEIGHT ? 0 : i + 1][j];
    count += gameField[i == 0 ? HEIGHT - 1 : i - 1][j + 1 == WIDTH ? 0 : j + 1];
    count += gameField[i][j == 0 ? WIDTH - 1 : j - 1] + gameField[i][j + 1 == WIDTH ? 0 : j + 1];
    count += gameField[i + 1 == HEIGHT ? 0 : i + 1][j == 0 ? WIDTH - 1 : j - 1];
    count += gameField[i + 1 == HEIGHT ? 0 : i + 1][j + 1 == WIDTH ? 0 : j + 1];

    return count;
}

void updateField(int** gameField) {
    int** newField = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        newField[i] = malloc(WIDTH * sizeof(int));
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = calcLifes(gameField, i, j);
            if (gameField[i][j] == 0 && count == 3) {
                newField[i][j] = 1;
            } else if (gameField[i][j] == 1 && (count == 3 || count == 2)) {
                newField[i][j] = 1;
            } else {
                newField[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gameField[i][j] = newField[i][j];
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        free(newField[i]);
    }
    free(newField);
}

void renderGame(int** gameField) {
    for (int i = -1; i < HEIGHT + 1; i++) {
        for (int j = -1; j < WIDTH + 1; j++)
            if ((i == -1 && j == -1) || (i == -1 && j == WIDTH) || (i == HEIGHT && j == -1) ||
                (i == HEIGHT && j == WIDTH))
                printw("+");
            else if (i == -1 || i == HEIGHT)
                printw("-");
            else if (j == -1 || j == WIDTH)
                printw("|");
            else if (gameField[i][j] == 1)
                printw("*");
            else
                printw(" ");
    }
}

void ingameInput(double* speed, int* active) {
    char set = getch();
    while (set != ERR) {
        if (set == 'a') {
            *speed = *speed * 1.1;
        } else if (set == 'z') {
            *speed = *speed / 1.1;
        } else if (set == 'q') {
            *active = 0;
        }
        set = getch();
    }
}

int pregameInput(int** gameField) {
    int coun_vib;
    int status = 1;
    if (scanw("%d", &coun_vib) != 1 || coun_vib < 0)
        status = 0;
    else {
        for (int i = 0; i < coun_vib && status; i++) {
            int x, y;
            if (scanw("%d %d", &x, &y) != 2)
                status = 0;
            else {
                gameField[x][y] = 1;
            }
        }
    }
    return status;
}
