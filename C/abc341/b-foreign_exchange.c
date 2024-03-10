#include <stdio.h>

int main() {
  int N;
  // 入力を受け取る
  if (scanf("%d", &N) != 1)
    return -1;

  long long A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%lld", &A[i]) != 1)
      return -1;
  }

  long long S[N - 1], T[N - 1];
  for (int i = 0; i < N - 1; i++) {
    if (scanf("%lld %lld", &S[i], &T[i]) != 2)
      return -1;
  }

  for (int i = 0; i < N - 1; i++) {
    long long ratio = A[i] / S[i];
    if (ratio > 0) {
      A[i] -= S[i] * ratio;
      A[i + 1] += T[i] * ratio;
    }

    // デバッグ出力：配列Aの内容
    printf("A array: ");
    for (int i = 0; i < N; i++) {
      printf("%lld ", A[i]);
    }
    printf("\n");
  }

  printf("%lld\n", A[N - 1]);

  return 0;
}
