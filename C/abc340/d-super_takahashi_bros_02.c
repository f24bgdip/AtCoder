#include <stdio.h>

#define MAX_N 200005
#define INF 1000000000000000LL

long long min(long long a, long long b) { return a < b ? a : b; }

int main() {
  int N;
  scanf("%d", &N);

  long long A[MAX_N], B[MAX_N], X[MAX_N];
  for (int i = 1; i < N; ++i) {
    scanf("%lld %lld %lld", &A[i], &B[i], &X[i]);
  }

  long long dp[MAX_N][2];
  dp[1][0] = 0;   // ステージ1はすぐ遊べる
  dp[1][1] = INF; // Bルートは最初から選択できない

  for (int i = 2; i <= N; ++i) {
    dp[i][0] = dp[i][1] = INF; // 初期値として十分大きな値を設定
  }

  for (int i = 1; i < N; ++i) {
    // Ai秒でステージiをクリアする場合
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + A[i]);
    dp[X[i]][1] = min(dp[X[i]][1], dp[i][0] + B[i]);

    // Bi秒でステージiをクリアする場合
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + B[i]);
    dp[X[i]][1] = min(dp[X[i]][1], dp[i][1] + A[i]);
  }

  // ステージNまでの最短時間を出力
  printf("%lld\n", min(dp[N][0], dp[N][1]));

  return 0;
}
