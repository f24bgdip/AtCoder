#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// descending order
int cmp_int(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int main() {
  int N, W;
  if (scanf("%d %d", &N, &W) != 2)
    return -1;

  int weights[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &weights[i]) != 1)
      return -1;
  }

  qsort(weights, N, sizeof(int), cmp_int);

  bool is_possible[W + 1];
  for (int w = 0; w <= W; w++) {
    is_possible[w] = false;
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    // 1個のおもりの重さ
    int w = weights[i];
    if (w > W)
      continue;
    if (!is_possible[w]) {
      is_possible[w] = true;
      count++;
      // printf("1=%d 2=  3= \n", weights[i]);
    }
    // 2個のおもりの重さ
    for (int j = i + 1; j < N; j++) {
      w = weights[i] + weights[j];
      if (w > W)
        continue;
      if (!is_possible[w]) {
        is_possible[w] = true;
        count++;
        // printf("1=%d 2=%d  3= \n", weights[i], weights[j]);
      }
      // 3個のおもりの重さ
      for (int k = j + 1; k < N; k++) {
        w = weights[i] + weights[j] + weights[k];
        if (w > W)
          continue;
        if (!is_possible[w]) {
          is_possible[w] = true;
          count++;
          // printf("1=%d 2=%d  3=%d \n", weights[i], weights[j], weights[k]);
        }
      }
    }
  }
  printf("%d\n", count);

  return 0;
}
