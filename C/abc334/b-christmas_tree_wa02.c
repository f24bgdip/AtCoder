#include <stdio.h>
#include <stdlib.h>

int main() {
  long long A, M, L, R;
  if (scanf("%lld %lld %lld %lld", &A, &M, &L, &R) != 4)
    return -1;

  long long x;
  if ((L - A) % M == 0) {
    A = L;
  } else {
    x = (L - A) / M + 1;
    A = A + x * M;
  }

  long long count;
  if (A > R) {
    count = 0;
  } else {
    count = (R - A) / M + 1;
  }

  printf("%lld\n", count);

  return 0;
}
