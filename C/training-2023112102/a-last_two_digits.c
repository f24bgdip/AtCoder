#include <stdio.h>

int main() {
  int N;

  if (scanf("%d", &N) != 1)
    return -1;

  printf("%02d\n", N % 100);

  return 0;
}
