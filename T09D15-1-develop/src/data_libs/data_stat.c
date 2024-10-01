#include "data_stat.h"
#include <math.h>

double max(double *data, int n) {
  double max_val = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] > max_val) {
      max_val = data[i];
    }
  }
  return max_val;
}

double min(double *data, int n) {
  double min_val = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] < min_val) {
      min_val = data[i];
    }
  }
  return min_val;
}

double mean(double *data, int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += data[i];
  }
  return sum / n;
}

double variance(double *data, int n) {
  double mean_val = mean(data, n);
  double sq_sum = 0.0;
  for (int i = 0; i < n; i++) {
    sq_sum += pow(data[i] - mean_val, 2);
  }
  return sq_sum / n;
}

void sort(double *data, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (data[i] > data[j]) {
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}