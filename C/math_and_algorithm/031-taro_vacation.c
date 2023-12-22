#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
long long int llmin(long long int a, long long int b) {
  return (a < b) ? a : b;
}
long long int llmax(long long int a, long long int b) {
  return (a > b) ? a : b;
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  long long dp[N + 1];
  dp[0] = 0;
  dp[1] = A[0];
  for (int i = 2; i <= N; i++) {
    dp[i] = llmax(dp[i - 1], dp[i - 2] + A[i - 1]);
  }

  printf("%lld\n", dp[N]);
  return 0;
}
