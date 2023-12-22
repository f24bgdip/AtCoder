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

  long long b[n];
  for (int i = 0; i < n; i++) {
    if (scanf("%lld", &b[i]) != 1)
      return -1;
  }

  long long a = b[0];
  for (int i = 1; i < n; i++) {
    a = gcd(a, b[i]);
  }
  printf("%lld\n", a);
  return 0;
}
