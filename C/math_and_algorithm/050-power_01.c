#include <stdio.h>

#define MOD 1000000007

int main(void) {
  long long a, b;
  if (scanf("%lld %lld", &a, &b) != 2)
    return -1;

  b %= MOD;
  long long r = 1;
  for (int i = 0; i < b; i++) {
    r = r * a % MOD;
  }

  printf("%lld\n", r);

  return 0;
}
