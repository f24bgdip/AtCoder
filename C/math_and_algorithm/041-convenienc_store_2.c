#include <stdio.h>

int main() {
  int T, N;
  if (scanf("%d %d", &T, &N) != 2)
    return -1;

  int count[T + 1];
  for (int i = 0; i <= T; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    int L, R;
    if (scanf("%d %d", &L, &R) != 2)
      return -1;
    count[L]++;
    count[R]--;
  }

  for (int i = 1; i <= T; i++) {
    count[i] += count[i - 1];
  }

  for (int t = 0; t < T; t++) {
    printf("%d\n", count[t]);
  }

  return 0;
}
