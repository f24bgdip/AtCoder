#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  long long n;
  if (scanf("%lld", &n) != 1)
    return -1;

  while (!(n % 2)) {
    n /= 2;
    printf("%lld ", 2LL);
  }

  for (long long i = 3; i <= floor(sqrt(n)); i += 2) {
    while (!(n % i)) {
      n /= i;
      printf("%lld ", i);
    }
  }

  if (n > 1)
    printf("%lld ", n);
  printf("\n");

  return 0;
}
