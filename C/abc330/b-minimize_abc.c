#include <stdio.h>

int main() {
  int N, L, R;
  if (scanf("%d %d %d", &N, &L, &R) != 3)
    return -1;

  for (int i = 0; i < N; i++) {
    int A;
    if (scanf("%d", &A) != 1)
      return -1;

    if (A < L) {
      printf("%d ", L);
    } else if (A > R) {
      printf("%d ", R);
    } else {
      printf("%d ", A);
    }
  }

  printf("\n");
  return 0;
}
