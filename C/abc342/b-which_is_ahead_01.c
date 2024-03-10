#include <stdio.h>

int main() {
  int N, Q;
  if (scanf("%d", &N) != 1)
    return -1;

  int P[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &P[i]) != 1)
      return -1;
  }

  if (scanf("%d", &Q) != 1)
    return -1;

  for (int i = 0; i < Q; i++) {
    int A, B;
    if (scanf("%d %d", &A, &B) != 2)
      return -1;

    int hA = 0;
    int hB = 0;

    for (int j = 0; j < N; j++) {
      if (P[j] == A) {
        hA = j;
      }
      if (P[j] == B) {
        hB = j;
      }
    }

    if (hA < hB) {
      printf("%d\n", A);
    } else {
      printf("%d\n", B);
    }
  }

  return 0;
}
