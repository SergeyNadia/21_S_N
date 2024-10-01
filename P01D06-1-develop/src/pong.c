#include <stdio.h>

#define wall '|'
#define left_rocket ']'
#define right_rocket '['
#define horizontal_wall '-'
#define space ' '
#define ball 'o'

int igra_ping_pong_red_apples();
int left_player(char key, int up_rocket_left, int down_rocket_left, int min_y, int height);
int right_player(char key, int up_rocket_right, int down_rocket_right, int min_y, int height);
int first_score(int ball_X, int left_ball_score);
int second_score(int ball_X, int right_ball_score);

int main() {
    int a;
    a = igra_ping_pong_red_apples();
    printf("\033[0d\033[2J");
    if (a == 0) {
        printf("Игрок 1 победил!\n");
    } else {
        printf("Игрок 2 победил!\n");
    }

    return 0;
}

int igra_ping_pong_red_apples() {
    int left_ball_score = 0;
    int right_ball_score = 0;

    while (right_ball_score != 21 || left_ball_score != 21) {
        int flag = 1;

        //положение ракеток
        int up_rocket_left = 11;
        int down_rocket_left = 13;
        int firstRacketX = 3;
        int up_rocket_right = 11;
        int down_rocket_right = 13;
        int secondRacketX = 76;

        //поле
        int height = 25;
        int width = 80;
        int min_y = 1;

        //координаты мяча
        int ball_X = 39;
        int ball_Y = 12;
        int pointSpeedX = 1;
        int pointSpeedY = 1;

        while (flag) {
            printf("\033[0d\033[2J");  //очистка экрана
            printf("Пинг-понгер 1: %d \t \t \t \t \t Пинг-понгер 2: %d\n", left_ball_score, right_ball_score);
            for (int i = 0; i < height; i++) {  //отрисовка поля в каждый момент цикла
                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1) {
                        printf("%c", wall);
                    } else if (j == width - 1) {
                        printf("%c", wall);
                    } else if (i == 0 || i == height - 1) {
                        printf("%c", horizontal_wall);
                    } else if (i == ball_Y && j == ball_X) {
                        printf("%c", ball);
                    } else if ((i >= up_rocket_left && i <= down_rocket_left && j == firstRacketX)) {
                        printf("%c", left_rocket);
                    } else if (i >= up_rocket_right && i <= down_rocket_right && j == secondRacketX) {
                        printf("%c", right_rocket);
                    } else if ((i != 0 && i != height) || (j != 0 && j != width)) {
                        printf("%c", space);
                    }
                }
                printf("\n");
            }

            //движение мяча относительно Y

            if (ball_Y == 23) pointSpeedY = -1;
            if (ball_Y == 1) pointSpeedY = 1;

            if ((up_rocket_right <= ball_Y && ball_Y <= down_rocket_right && ball_X == secondRacketX - 1))
                pointSpeedX = -1;
            if (up_rocket_left <= ball_Y && ball_Y <= down_rocket_left && ball_X == firstRacketX + 1)
                pointSpeedX = 1;

            left_ball_score = first_score(ball_X, left_ball_score);
            right_ball_score = second_score(ball_X, right_ball_score);

            if (ball_X == 0 || ball_X == 79) flag = 0;
            if (left_ball_score == 21) return 0;
            if (right_ball_score == 21) return 1;

            //считывание клавиатуры
            char key = getchar();

            if (left_player(key, up_rocket_left, down_rocket_left, min_y, height) == 1) {
                up_rocket_left++;
                down_rocket_left++;
            } else if (left_player(key, up_rocket_left, down_rocket_left, min_y, height) == -1) {
                up_rocket_left--;
                down_rocket_left--;
            }

            if (right_player(key, up_rocket_right, down_rocket_right, min_y, height) == 1) {
                up_rocket_right++;
                down_rocket_right++;
            } else if (right_player(key, up_rocket_right, down_rocket_right, min_y, height) == -1) {
                up_rocket_right--;
                down_rocket_right--;
            }
            if (key == '\n') {
                ball_X += pointSpeedX;
                ball_Y += pointSpeedY;
            }
        }
    }
    return 0;
}

//клавиши
int left_player(char key, int up_rocket_left, int down_rocket_left, int min_y, int height) {
    if (key == 'a' && up_rocket_left != min_y) return -1;
    if (key == 'z' && down_rocket_left != height - 2) return 1;
    return 0;
}

int right_player(char key, int up_rocket_right, int down_rocket_right, int min_y, int height) {
    if (key == 'k' && up_rocket_right != min_y) return -1;
    if (key == 'm' && down_rocket_right != height - 2) return 1;
    return 0;
}

//счет
int first_score(int ball_X, int left_ball_score) {
    if (ball_X == 79) {
        ball_X = 39;
        if (left_ball_score != 21) left_ball_score++;
    }
    return left_ball_score;
}

int second_score(int ball_X, int right_ball_score) {
    if (ball_X == 0) {
        ball_X = 39;
        if (right_ball_score != 21) right_ball_score++;
    }
    return right_ball_score;
}