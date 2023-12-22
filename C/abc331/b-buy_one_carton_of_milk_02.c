#include <stdio.h>

int main(void) {
  int N, S, M, L;
  if (scanf("%d %d %d %d", &N, &S, &M, &L) != 4)
    return -1;

  int max_s = N / 6 + 1;
  int max_m = N / 8 + 1;
  int max_l = N / 12 + 1;
  int cost = 100 * 1e4;
  for (int i = 0; i <= max_s; i++) {
    for (int j = 0; j <= max_m; j++) {
      for (int k = 0; k <= max_l; k++) {
        if (6 * i + 8 * j + 12 * k >= N) {
          cost = (cost < S * i + M * j + L * k) ? cost : S * i + M * j + L * k;
        }
      }
    }
  }

  printf("%d\n", cost);

  return 0;
}
