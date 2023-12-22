#include <stdio.h>

int main(void) {
  int mandarin;

  if (scanf("%d", &mandarin) != 1)
    return -1;

  printf("%d\n", mandarin + 5);

  return 0;
}
