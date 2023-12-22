#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  long long n;
  if (scanf("%lld", &n) != 1)
    return -1;

  long long rootn = floor(sqrt(n));
  for (long long i = 1; i <= rootn; i++) {
    if (!(n % i)) {
      printf("%lld\n", i);
      if (i != n / i) {
        printf("%lld\n", n / i);
      }
    }
  }
  return 0;
}
