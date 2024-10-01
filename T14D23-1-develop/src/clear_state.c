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

int compare_dates(const void *a, int day, int month, int year) {
    const Record *rec1 = (const Record *)a;
    int result = 0;

    if (rec1->year != year) {
        result = (rec1->year > year) ? 1 : -1;
    } else if (rec1->month != month) {
        result = (rec1->month > month) ? 1 : -1;
    } else if (rec1->day != day) {
        result = (rec1->day > day) ? 1 : -1;
    }

    return result;
}

void parse_date(const char *date_str, int *day, int *month, int *year) {
    sscanf(date_str, "%2d.%2d.%4d", day, month, year);
}

void clear_records(const char *filename, int start_day, int start_month, int start_year, int end_day,
                   int end_month, int end_year) {
    FILE *file = fopen(filename, "rb+");
    FILE *temp_file = fopen("temp.bin", "wb");

    Record record;
    int is_within_range;

    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        is_within_range = compare_dates(&record, start_day, start_month, start_year) >= 0 &&
                          compare_dates(&record, end_day, end_month, end_year) <= 0;
        // запись только тех записей, которые находятся вне указанного диапазона
        if (!is_within_range) {
            fwrite(&record, RECORD_SIZE, 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename("temp.bin", filename);
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    Record record;
    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        printf("%d-%02d-%02d %02d:%02d:%02d %d %d\n", record.year, record.month, record.day, record.hour,
               record.minute, record.second, record.status, record.code);
    }
    fclose(file);
}

int main() {
    char filename[259];
    char filepath[256];
    char start_date[11], end_date[11];
    int valid_input = 1;

    if (scanf("%255s", filepath) != 1) {
        printf("n/a");
        valid_input = 0;
    }
    strcpy(filename, "../");
    strcat(filename, filepath);

    if (valid_input) {
        if (scanf("%10s %10s", start_date, end_date) != 2) {
            printf("n/a");
            valid_input = 0;
        }
    }

    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    if (valid_input) {
        parse_date(start_date, &start_day, &start_month, &start_year);
        parse_date(end_date, &end_day, &end_month, &end_year);

        clear_records(filename, start_day, start_month, start_year, end_day, end_month, end_year);
        print_file(filename);
    }

    return 0;
}