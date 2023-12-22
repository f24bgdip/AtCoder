#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  long long D;
  if (scanf("%lld", &D) != 1)
    return -1;

  long long min_diff = LLONG_MAX;
  long long x = (long long)sqrt(D);
  long long y = 0;

  while (x >= 0 && y <= x) {
    long long diff = llabs(x * x + y * y - D);
    if (diff < min_diff) {
      min_diff = diff;
    }

    if (x * x + y * y > D) {
      x--;
    } else {
      y++;
    }
  }

  printf("%lld\n", min_diff);
  return 0;
}
