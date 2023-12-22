#include <stdio.h>

int main() {
  int N, K;
  long long int total = 1;
  const int MOD = 2e31 - 1;

  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  total *= K;

  for (int i = 1; i < N; i++) {
    total *= (K - 1);
    total %= MOD;
  }

  printf("%lld\n", total);

  return 0;
}
