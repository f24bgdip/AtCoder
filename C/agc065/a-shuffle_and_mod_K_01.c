#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int main() {
  int N, K;
  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  qsort(A, N, sizeof(int), compare);

  int sum = 0;
  for (int i = 0; i < N - 1; i++) {
    int diff = A[i + 1] - A[i];
    int mod = diff % K;
    if (mod < 0) {
      mod += K;
    }
    sum += mod;
    // printf("(%d - %d) %% %d = %d\n", A[i + 1], A[i], K, mod);
  }

  printf("%d\n", sum);
  return 0;
}
