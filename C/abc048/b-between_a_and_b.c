#include <stdio.h>

int main() {
  long long a, b, x;
  if (scanf("%lld %lld %lld", &a, &b, &x) != 3)
    return -1;

  long long first = a + (x - a % x) % x;
  long long last = b - b % x;
  long long count = (last - first) / x + 1;

  printf("%lld\n", count);

  return 0;
}
