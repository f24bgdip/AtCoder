#include <stdio.h>
#include <stdlib.h>

int main() {
  long long A, M, L, R;
  if (scanf("%lld %lld %lld %lld", &A, &M, &L, &R) != 4)
    return -1;

  long long x;
  if ((L - A) % M == 0) {
    x = (L - A) / M;
  } else {
    x = (L - A) / M + 1;
  }

  long long y = (R - A) / M;

  long long count = 0;
  if (A <= R) {
    count = y - x + 1;
    if (count < 0) {
      count = 0;
    }
  }

  printf("%lld\n", count);

  return 0;
}
