#include <stdio.h>

void func(int v[], int n) {
  int i, j, t, min_index;
  for (i = 0; i < n - 1; ++i) {
    min_index = i;
    for (j = i + 1; j < n; ++j) {
      if (v[j] < v[min_index]) {
        min_index = j;
      }
    }
    t = v[i];
    v[i] = v[min_index];
    v[min_index] = t;

    for (int k = 0; k < n; ++k) {
      printf("%d", v[k]);
    }
    puts("\n");
  }
}

int main() {
  int array[5] = {30, 50, 20, 10, 40};
  func(array, 5);
  printf("%d\n", array[2]);

  return 0;
}