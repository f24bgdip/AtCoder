#include <limits.h>
#include <stdio.h>

#define MAX_N 50
#define MAX_A 50
#define MAX_SUM (MAX_N * MAX_A)

long long dp[MAX_N + 1][MAX_N + 1][MAX_N * MAX_A + 1];

int main(void) {
  int n, a;
  int x[MAX_N];

  scanf("%d %d", &n, &a);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  // 初期化
  dp[0][0][0] = 1;

  // DPテーブルを更新
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= MAX_SUM; ++k) {
        if (dp[i][j][k]) {
          // カードiを選ばない場合
          dp[i + 1][j][k] += dp[i][j][k];
          // カードiを選ぶ場合
          dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
        }
      }
    }
  }

  // 結果を計算
  long long result = 0;
  for (int j = 1; j <= n; ++j) {
    for (int k = 0; k <= MAX_SUM; ++k) {
      if (j * a == k) {
        result += dp[n][j][k];
      }
    }
  }

  printf("%lld\n", result);

  return 0;
}
