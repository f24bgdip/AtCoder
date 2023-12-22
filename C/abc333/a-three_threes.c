#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  for (int i = 0; i < N; i++) {
    printf("%d", N);
  }
  printf("\n");

  return 0;
}
