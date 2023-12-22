#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A;
  double sum_a = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A) != 1)
      return -1;
    sum_a += A * (1.0 / 3);
  }

  int B;
  double sum_b = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &B) != 1)
      return -1;
    sum_b += B * (2.0 / 3);
  }

  printf("%.6f\n", sum_a + sum_b);

  return 0;
}
