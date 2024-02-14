#include <stdio.h>

#define MOD 1000000007

typedef long long ll;

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll A;
    if (scanf("%lld", &A) != 1)
      return -1;
    ll add = (A * ((1LL << i) % MOD)) % MOD;
    sum = (sum + add) % MOD;
  }
  printf("%lld\n", sum);

  return 0;
}
