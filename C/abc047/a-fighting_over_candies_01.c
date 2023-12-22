#include <stdio.h>
#include <stdlib.h>

void main(void) {
  unsigned int n[3];
  unsigned int i;

  if (scanf("%u %u %u", &n[0], &n[1], &n[2]) == 0)
    return;

  bool for (i = 0; i < 3; i++) {
    if (n[(i % 3)] == n[(i + 1) % 3] + n[(i + 2) % 3])
      goto good;
  }

bad:
  printf("No");
  return;

good:
  printf("Yes");
  return;
}
