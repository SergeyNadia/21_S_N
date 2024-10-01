#include "work_with_file.h"

int main() {
    FILE *file = NULL;
    char path[SIZE];
    int mode = 0;
    int result = 1;
    while (mode != -1) {
        if (scanf("%d", &mode) == 1) {
            if (mode < -1 || mode > 4 || mode == 0) result = !result;
            switch (mode) {
                case 1:
                    result = read_file(file, path);
                    break;
                case 2:
                    result = write_in_file(file, path);
                    break;
                case 3:
                    int shift;
                    scanf("%d", &shift);
                    caesar_cipher("/ai_modules", "/ai_modules", shift);
                    break;
                case 4:
                    des_encrypt("/ai_modules");
                    break;
            }
        } else {
            result = !result;
            scanf("%*s");
        }
        if (!result) {
            printf("n/a\n");
            result = !result;
        }
    }
    return 0;
}