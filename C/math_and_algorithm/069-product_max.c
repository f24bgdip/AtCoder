#include <limits.h>
#include <stdio.h>

typedef long long ll;

int main() {
  ll x[2], y[2];
  if (scanf("%lld %lld %lld %lld", &x[0], &x[1], &y[0], &y[1]) != 4)
    return -1;

  ll max_product = LLONG_MIN;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      ll product = x[i] * y[j];
      if (max_product < product)
        max_product = product;
    }

  printf("%lld\n", max_product);

  return 0;
}
