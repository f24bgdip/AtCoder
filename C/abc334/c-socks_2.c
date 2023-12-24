#include <stdio.h>

int main() {
  int N, K;
  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  int A[K];
  for (int i = 0; i < K; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  int cost = 0;
  if ((2 * N - K) % 2 == 0) {
    // 偶数の場合
    for (int i = 1; i < K; i += 2) {
      cost += A[i] - A[i - 1];
    }
  } else {
    // 奇数の場合
    int now = 0;
    for (int i = 2; i < K; i += 2) {
      // 0番目のケースを除いた結果を計算
      now += A[i] - A[i - 1];
    }
    cost = now;
    for (int i = 2; i < K; i += 2) {
      // 前に引いたものを戻す
      now += A[i - 1] - A[i - 2];
      // 次のものを引く
      now -= A[i] - A[i - 1];
      cost = now < cost ? now : cost;
    }
  }

  printf("%d\n", cost);

  return 0;
}
