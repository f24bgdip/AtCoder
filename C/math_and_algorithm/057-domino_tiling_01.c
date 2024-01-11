#include <stdio.h>

#define MOD 1000000007

// 2xNグリッドにドミノを敷き詰める方法の数を計算する関数
int countDominoTilings(int N) {
  // dp[i]は2xiグリッドにドミノを敷き詰める方法の数
  long long dp[N + 1];
  dp[0] = 1; // 初期化
  dp[1] = 1; // 2x1グリッドには1つの方法しかない

  for (int i = 2; i <= N; i++) {
    // 現在の列を考慮したときの敷き詰め方の数は、
    // 一つ前の列の数と二つ前の列の数の合計
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }
  return dp[N];
}

int main() {
  int K, N;
  if (scanf("%d %d", &K, &N) != 2)
    return -1;

  printf("%d\n", countDominoTilings(N));
  return 0;
}
