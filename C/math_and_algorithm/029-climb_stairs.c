#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int dp[N + 1];
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  printf("%d\n", dp[N]);
  return 0;
}
