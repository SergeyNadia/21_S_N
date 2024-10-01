#include "data_process.h"
#include <stdio.h>
#include <stdlib.h>

#define INCLUDE_IO
#define INCLUDE_STAT

#ifdef INCLUDE_IO
#include "../data_libs/data_io.h"
#endif

#ifdef INCLUDE_STAT
#include "../data_libs/data_stat.h"
#endif

int main() {
  double *data;
  int n;
  scanf("%d", &n);

  // Выделение памяти для массива данных
  data = (double *)malloc(n * sizeof(double));
  if (data == NULL) {
    printf("Error memory\n");
    return 1;
  }

  // Ввод данных
  input(data, n);

  // Проверка нормализации данных
  if (normalization(data, n)) {
    // Вывод обработанных данных
    output(data, n);
  } else {
    printf("Error\n");
  }

  // Освобождение памяти
  free(data);

  return 0;
}
