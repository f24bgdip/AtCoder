#include <stdio.h>

void main(void) {
  unsigned int phrase[3];
  unsigned int sum;
  int i;

  if (scanf("%u %u %u", &phrase[0], &phrase[1], &phrase[2]) == 0)
    goto no;

  sum = phrase[0] + phrase[1] + phrase[2];
  if (sum != 17)
    goto no;

  sum = 0;
  for (i = 0; i < 3; i++) {
    if (phrase[i] == 5)
      sum += 5;
    else if (phrase[i] == 7)
      sum += 7;
  }

  if (sum != 17)
    goto no;

  printf("YES");

  return;

no:
  printf("NO");

  return;
}
