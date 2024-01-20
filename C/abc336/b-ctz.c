#include <stdio.h>

int ctz(int n) {
  int count = 0;
  while ((n & 1) == 0 && n > 0) {
    count++;
    n = n >> 1;
  }
  return count;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int result = ctz(N);
  printf("%d\n", result);

  return 0;
}
