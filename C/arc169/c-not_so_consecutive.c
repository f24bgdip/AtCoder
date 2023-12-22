#include <stdio.h>
#define MOD 998244353

int main() {
  int N;
  scanf("%d", &N);

  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // ここに動的計画法のアルゴリズムを実装
  // dp[i][j] を i 番目の位置に j を置いた場合の「よい数列」の数とする
  long long dp[N + 1][N + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1; // 初期化

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i - 1] == -1 || A[i - 1] == j) {
        // 各数が i+1 回以上連続しないようにカウント
        for (int k = 1; k <= N; k++) {
          if (k != j || i < j + 1) {
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
          }
        }
      }
    }
  }

  // すべての組み合わせの合計を計算
  long long result = 0;
  for (int j = 1; j <= N; j++) {
    result = (result + dp[N][j]) % MOD;
  }

  printf("%lld\n", result);
  return 0;
}
