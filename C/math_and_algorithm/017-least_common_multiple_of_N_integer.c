#include <stdio.h>

long long gcd(long long a, long long b) {
  while (b != 0) {
    long long t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  long long a;
  if (scanf("%lld", &a) != 1)
    return -1;

  for (int i = 1; i < n; i++) {
    long long b, d;
    scanf("%lld", &b);
    d = gcd(a, b);
    a = (a / d) * b;
  }
  printf("%lld\n", a);
  return 0;
}
