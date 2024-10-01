#include <stdarg.h>
#include <stdio.h>
#ifdef DOC
#include <stdlib.h>

#include "documentation_module.h"
#endif
#include "print_module.h"

int main() {
    print_log(print_char, Module_load_success_message);

#ifdef DOC
    char *documents[] = {Documents};
    int documents_count = Documents_count;

    int *availability_mask = check_available_documentation_module(validate, documents_count, documents[0],
                                                                  documents[1], documents[2], documents[3]);

    if (availability_mask != NULL) {
        for (int i = 0; i < documents_count; i++) {
            printf("%-15s : %s\n", documents[i], availability_mask[i] ? "available" : "unavailable");
        }
    }

    // Освобождаем память
    free(availability_mask);
#endif

    return 0;
}
