#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int h[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &h[i]) != 1)
      return -1;
  }

  int dp[N];
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < N; i++) {
    dp[i] = fmin(dp[i - 1] + abs(h[i] - h[i - 1]),
                 dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  printf("%d\n", dp[N - 1]);
  return 0;
}