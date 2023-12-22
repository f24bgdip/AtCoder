#include <stdio.h>

int main() {
  int N, S, K, i;
  int total = 0;

  if (scanf("%d %d %d", &N, &S, &K) != 3)
    return -1;

  for (i = 0; i < N; i++) {
    int P, Q;
    if (scanf("%d %d", &P, &Q) != 2)
      return -1;
    total += P * Q;
  }

  if (total < S) {
    total += K;
  }
  printf("%d\n", total);

  return 0;
}
