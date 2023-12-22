#include <stdio.h>

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int B, R;
  double sum_b = 0, sum_r = 0;

  for (int i = 0; i < N; i++) {
    if (scanf("%d", &B) != 1)
      return -1;
    sum_b += B;
  }

  for (int i = 0; i < N; i++) {
    if (scanf("%d", &R) != 1)
      return -1;
    sum_r += R;
  }

  double average_b = sum_b / N;
  double average_r = sum_r / N;

  printf("%.6f\n", average_b + average_r);

  return 0;
}
