#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  long long n;
  if (scanf("%lld", &n) != 1)
    return -1;

  if (n == 2) {
    printf("Yes\n");
    return 0;
  }

  if (n % 2 == 0) {
    printf("No\n");
    return 0;
  }

  long long rt = floor(sqrt(n));
  for (long long i = 3; i <= rt; i += 2) {
    if (!(n % i)) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
