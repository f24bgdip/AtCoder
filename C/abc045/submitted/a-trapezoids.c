#include <stdio.h>

void main(void) {
  unsigned int l[3];
  unsigned int i, ans;

  for (i = 0; i < 3; i++) {
    if (scanf("%u", &l[i]) == 0)
      return;
  }

  ans = (l[0] + l[1]) * l[2] / 2;

  printf("%u", ans);

  return;
}
