#include <stdio.h>

int main(void) {
  int N;

  if (scanf("%d", &N) != 1)
    return -1;

  for (int i = N / 10;; i++) {
    int p = i / 10;
    int q = i % 10;
    int r = p * q;
    if (r <= 9 && p * 100 + q * 10 + r >= N) {
      printf("%d\n", p * 100 + q * 10 + r);
      break;
    }
  }
  return 0;
}
