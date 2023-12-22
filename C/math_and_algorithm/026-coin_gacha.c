#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  double expected_value = 0.0;
  for (int i = 1; i <= N; i++) {
    expected_value += (double)N / i;
  }

  printf("%.6f\n", expected_value);
  return 0;
}
