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

int compare_records(const void *a, const void *b) {
    const Record *rec1 = (const Record *)a;
    const Record *rec2 = (const Record *)b;
    int result = 0;

    if (rec1->year != rec2->year) {
        result = (rec1->year > rec2->year) ? 1 : -1;
    } else if (rec1->month != rec2->month) {
        result = (rec1->month > rec2->month) ? 1 : -1;
    } else if (rec1->day != rec2->day) {
        result = (rec1->day > rec2->day) ? 1 : -1;
    } else if (rec1->hour != rec2->hour) {
        result = (rec1->hour > rec2->hour) ? 1 : -1;
    } else if (rec1->minute != rec2->minute) {
        result = (rec1->minute > rec2->minute) ? 1 : -1;
    } else if (rec1->second != rec2->second) {
        result = (rec1->second > rec2->second) ? 1 : -1;
    }

    // если все временные поля совпадают, сравниваем статус
    if (result == 0) {
        if (rec1->status != rec2->status) {
            result = (rec1->status > rec2->status) ? 1 : -1;
        } else if (rec1->code != rec2->code) {
            result = (rec1->code > rec2->code) ? 1 : -1;
        }
    }

    return result;
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

void sort_file(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int num_records = (file_size != 0) ? file_size / RECORD_SIZE : 0;

    if (num_records > 0) {
        Record record1, record2;
        int sorted = 0;
        while (!sorted) {
            sorted = 1;  // Предполагаем, что массив отсортирован
            for (int i = 0; i < num_records - 1; i++) {
                // Чтение первой записи
                fseek(file, i * RECORD_SIZE, SEEK_SET);
                fread(&record1, RECORD_SIZE, 1, file);

                // Чтение следующей записи
                fseek(file, (i + 1) * RECORD_SIZE, SEEK_SET);
                fread(&record2, RECORD_SIZE, 1, file);

                // Если порядок нарушен, меняем записи местами
                if (compare_records(&record1, &record2) > 0) {
                    // Меняем местами
                    fseek(file, i * RECORD_SIZE, SEEK_SET);
                    fwrite(&record2, RECORD_SIZE, 1, file);

                    fseek(file, (i + 1) * RECORD_SIZE, SEEK_SET);
                    fwrite(&record1, RECORD_SIZE, 1, file);

                    sorted = 0;  // Массив не отсортирован, продолжаем
                }
            }
        }
    } else {
        printf("n/a\n");
    }
    fclose(file);
}

void add_record(const char *filename) {
    FILE *file = fopen(filename, "ab");
    Record record;
    int result = scanf("%d %d %d %d %d %d %d %d", &record.year, &record.month, &record.day, &record.hour,
                       &record.minute, &record.second, &record.status, &record.code);
    if (result == 8) {
        fwrite(&record, RECORD_SIZE, 1, file);
    } else {
        printf("n/a\n");
    }
    fclose(file);
}

int main() {
    char filename[259];
    char filepath[256];
    int choice;
    int valid_input = 1;

    if (scanf("%255s", filepath) != 1) {
        printf("n/a\n");
        valid_input = 0;
    }
    strcpy(filename, "../");
    strcat(filename, filepath);
    while (valid_input) {
        int input_status = scanf("%d", &choice);
        FILE *file = fopen(filename, "rb");
        if (input_status != 1 || file == NULL) {
            printf("n/a\n");
            valid_input = 0;
        } else {
            switch (choice) {
                case 0:
                    print_file(filename);
                    valid_input = 0;
                    break;
                case 1:
                    sort_file(filename);
                    print_file(filename);
                    valid_input = 0;
                    break;
                case 2:
                    add_record(filename);
                    sort_file(filename);
                    print_file(filename);
                    valid_input = 0;
                    break;
                default:
                    printf("n/a\n");
                    valid_input = 0;
                    break;
            }
        }
    }

    return 0;
}