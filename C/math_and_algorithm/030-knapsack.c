#include <stdio.h>
#include <stdlib.h>

long long int llmax(long long int a, long long int b) { return (a > b) ? a : b; }

int main() {
  int N, W;
  if (scanf("%d %d", &N, &W) != 2)
    return -1;

  int weights[N];
  long long int values[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d %lld", &weights[i], &values[i]) != 2)
      return -1;
  }

  long long int dp[N + 1][W + 1];
  for (int i = 0; i <= N; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      } else if (weights[i - 1] <= w) {
        dp[i][w] =
            llmax(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  printf("%lld\n", dp[N][W]);
  return 0;
}
