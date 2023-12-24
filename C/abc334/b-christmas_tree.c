#include <stdio.h>

int main() {
  long long a, m, l, r;
  scanf("%lld %lld %lld %lld", &a, &m, &l, &r);

  l -= a;
  r -= a;

  if (l < 0 || l % m == 0)
    l /= m;
  else
    l = l / m + 1;

  if (r > 0 || r % m == 0)
    r /= m;
  else
    r = r / m - 1;

  printf("%lld", r - l + 1);
  return 0;
}
