#include <limits.h>
#include <stdio.h>

long long int_pow(int base, int exp) {
  long long result = 1;
  for (int i = 0; i < exp; ++i) {
    if (LLONG_MAX / result < base) {
      return LLONG_MAX;
    }
    result *= base;
  }
  return result;
}

int main() {
  long long B;

  if (scanf("%lld", &B) != 1)
    return -1;

  int i;
  for (i = 1; i < 16; i++) {
    long long result = int_pow(i, i);

    if (result == B)
      break;
  }

  if (i >= 16) {
    printf("-1\n");
  } else {
    printf("%d\n", i);
  }

  return 0;
}
