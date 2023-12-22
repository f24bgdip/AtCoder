#include <stdio.h>

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  int A[N + 1];
  A[0] = 0;
  for (int i = 1; i <= N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
    // 累積和を計算
    A[i] += A[i - 1];
  }

  for (int i = 0; i < Q; i++) {
    int L, R;
    if (scanf("%d %d", &L, &R) != 2)
      return -1;
    // 範囲の合計来場者数を計算
    printf("%d\n", A[R] - A[L - 1]);
  }

  return 0;
}
