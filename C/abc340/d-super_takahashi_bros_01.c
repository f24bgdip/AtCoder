#include <stdio.h>

#define MAX_N 200005
#define INF 1000000000000000LL

long long min(long long a, long long b) { return a < b ? a : b; }

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  long long A[N], B[N], X[N];
  for (int i = 1; i < N; ++i) {
    if (scanf("%lld %lld %lld", &A[i], &B[i], &X[i]) != 3)
      return -1;
  }

  long long dp[N+1];
  dp[1] = 0;

  for (int i = 2; i <= N; ++i) {
    dp[i] = INF;
  }

  for (int i = 1; i < N; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + A[i]);
    dp[X[i]] = min(dp[X[i]], dp[i] + B[i]);
  }

  printf("%lld\n", dp[N]);

  return 0;
}
