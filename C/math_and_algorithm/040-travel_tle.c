#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;
  int A[N - 1];
  for (int i = 0; i < N - 1; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  int M;
  if (scanf("%d", &M) != 1)
    return -1;
  int B[M];
  for (int i = 0; i < M; i++) {
    if (scanf("%d", &B[i]) != 1)
      return -1;
  }

  long long total = 0;
  for (int i = 0; i < M - 1; i++) {
    if (B[i] < B[i + 1]) {
      for (int j = B[i]; j < B[i + 1]; j++) {
        total += A[j - 1];
      }
    } else {
      for (int j = B[i] - 2; j >= B[i + 1] - 1; j--) {
        total += A[j];
      }
    }
  }
  printf("%lld\n", total);
  return 0;
}
