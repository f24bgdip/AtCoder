#include <stdio.h>

int main() {
  long long A, M, L, R;
  if (scanf("%lld %lld %lld %lld", &A, &M, &L, &R) != 4)
    return -1;

  L -= A, R -= A;
  long long x = (L > 0) ? (L / M + 1) : (L / M);
  long long y = (R >= 0) ? (R / M) : (R / M - 1);
  long long count = y - x + 1;
  if (count < 0) {
    count = 0;
  }

  printf("%lld\n", count);

  return 0;
}
