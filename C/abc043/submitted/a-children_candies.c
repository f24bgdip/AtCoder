#include <stdio.h>

void main(void) {
  unsigned int n, ans;

  if (scanf("%u", &n) == 0)
    return;

  ans = (1 + n) * n / 2;

  printf("%u", ans);

  return;
}
