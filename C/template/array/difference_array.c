#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  // 差分配列
  int A[N + 1];
  for (int i = 0; i <= N; i++)
    A[i] = 0;

  for (int i = 0; i < Q; i++) {
    int L, R, X;
    if (scanf("%d %d %d", &L, &R, &X) != 3)
      return -1;
    // 開始点を加算
    A[L - 1] += X;
    // 終了点の次の点を減算
    A[R] -= X;
  }

  // 累積和を計算する
  for (int i = 0; i < N - 1; i++) {
    A[i + 1] += A[i];
    printf("%d ", A[i]);
  }
  printf("%d\n", A[N - 1]);

  return 0;
}
