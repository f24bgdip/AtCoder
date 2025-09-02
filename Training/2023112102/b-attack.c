#include <stdio.h>

int main() {
  long long A, B;

  if (scanf("%lld %lld", &A, &B) != 2)
    return -1;

  long long attacks = A / B;
  if (A % B != 0) {
    attacks++;
  }

  printf("%lld\n", attacks);

  return 0;
}
