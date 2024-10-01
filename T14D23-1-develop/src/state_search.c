#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_SIZE \
    (sizeof(int) * 7 + sizeof(int))  // год, месяц, день, час, минута, секунда, статус (0/1), код

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;

void parse_date(const char *date_str, int *day, int *month, int *year) {
    sscanf(date_str, "%2d.%2d.%4d", day, month, year);
}

int main() {
    char filename[259];
    char filepath[256];
    char date_str[11];
    int valid_input = 1;

    if (scanf("%255s", filepath) != 1) {
        printf("n/a");
        valid_input = 0;
    }
    strcpy(filename, "../");
    strcat(filename, filepath);

    if (valid_input) {
        if (scanf("%10s", date_str) != 1) {
            printf("n/a");
            valid_input = 0;
        }
    }
    int search_day, search_month, search_year;
    if (valid_input) {
        parse_date(date_str, &search_day, &search_month, &search_year);
    }

    FILE *file = NULL;
    if (valid_input) {
        file = fopen(filename, "rb");
        if (file == NULL) {
            printf("n/a");
            valid_input = 0;
        }
    }
    Record record;
    if (valid_input) {
        int found = 0;
        while (fread(&record, RECORD_SIZE, 1, file) == 1) {
            if (record.day == search_day && record.month == search_month && record.year == search_year) {
                printf("%d\n", record.code);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("n/a");
        }
    }

    if (file != NULL) {
        fclose(file);
    }
    return 0;
}