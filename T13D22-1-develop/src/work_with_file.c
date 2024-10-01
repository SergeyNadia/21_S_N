#include "work_with_file.h"

#include <stdlib.h>
#include <string.h>

#include "log_levels.h"
#include "logger.h"

#define MAX_PATH 1024
#define BLOCK_SIZE 64

typedef struct {
    char d_name[MAX_PATH];
} dirent_t;

int read_file(FILE *file, char *path) {
    FILE *f = log_init("LOG.txt");
    int rtn = 1;
    scanf("%255s", path);
    file = fopen(path, "rt");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos > 0) {
            logcat(f, path, "FILE IS NOT EMPTY", INFO);
            char string[SIZE];
            rewind(file);
            while (fgets(string, sizeof(string), file)) {
                printf("%s", string);
            }
        } else {
            logcat(f, path, "FILE IS EMPTY", WARNING);
            rtn = 0;
        }
        fclose(file);
    } else {
        logcat(f, path, "FILE DOES NOT EXIST", ERROR);
        rtn = 0;
    }
    if (rtn) {
        logcat(f, path, "FILE READ", INFO);
        printf("\n");
    }
    log_close(f);
    return rtn;
}

int write_in_file(FILE *file, char *path) {
    FILE *f = log_init("LOG.txt");
    int rtn = 1;
    char string[SIZE];
    getchar();
    fgets(string, sizeof(string), stdin);
    if (string[strlen(string) - 1] == '\n') string[strlen(string) - 1] = '\0';
    file = fopen(path, "r+");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos != 0) fprintf(file, "%c", '\n');
        fprintf(file, "%s", string);
        rewind(file);
        while (fgets(string, sizeof(string), file)) {
            printf("%s", string);
        }
        fclose(file);
    } else {
        logcat(f, path, "FILE IS NOT OPEN FOR WRITING", ERROR);
        rtn = 0;
    }
    if (rtn) {
        printf("\n");
        logcat(f, path, "WRITING TO FILE SUCCESSFULLY", INFO);
    }
    log_close(f);
    return rtn;
}

void caesar_cipher(const char *input_file, const char *output_file, int shift) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        fprintf(stderr, "Ошибка при открытии файла\n");
        exit(1);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), input)) {
        for (unsigned int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = ((buffer[i] - 'a' + shift) % 26) + 'a';
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = ((buffer[i] - 'A' + shift) % 26) + 'A';
            }
        }
        fprintf(output, "%s", buffer);
    }

    fclose(input);
    fclose(output);
}

void des_encrypt(const char *directory) {
    // Получаем список файлов в директории
    char command[256];
    snprintf(command, sizeof(command), "ls -p '%s'", directory);

    // Запускаем команду и читаем ее вывод
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        fprintf(stderr, "Ошибка при открытии команды\n");
        return;
    }

    char buffer[256];
    int bytes_read;

    // Читаем файлы из директории
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), pipe)) > 0) {
        buffer[bytes_read] = '\0';  // Добавляем конец строки
        char *item = strtok(buffer, "\n");

        if (!item || strcmp(item, ".") == 0 || strcmp(item, "..") == 0) continue;

        if (strstr(item, ".c")) {
            char input_path[256], output_path[256];
            snprintf(input_path, sizeof(input_path), "%s%s", directory, item);
            snprintf(output_path, sizeof(output_path), "%s/.des_%s", directory, item);

            FILE *input = fopen(input_path, "rb");
            if (!input) {
                fprintf(stderr, "Ошибка при открытии файла для чтения: %s\n", input_path);
                continue;
            }

            FILE *output = fopen(output_path, "wb");
            if (!output) {
                fprintf(stderr, "Ошибка при открытии файла для записи: %s\n", output_path);
                fclose(input);
                continue;
            }

            unsigned char buffer[BLOCK_SIZE];
            int bytes_read;

            while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input)) > 0) {
                // Здесь нужно реализовать DES шифрование без использования библиотеки
                // Например, используя циклы и битовые операции

                fwrite(buffer, 1, bytes_read, output);
            }

            fclose(input);
            fclose(output);
        } else if (strstr(item, ".h")) {
            char input_path[256], output_path[256];
            snprintf(input_path, sizeof(input_path), "%s%s", directory, item);
            snprintf(output_path, sizeof(output_path), "%s/.empty_%s", directory, item);

            FILE *file = fopen(output_path, "w");
            if (!file) {
                fprintf(stderr, "Ошибка при открытии файла: %s\n", output_path);
                continue;
            }
            fclose(file);
        }
    }

    pclose(pipe);
}
