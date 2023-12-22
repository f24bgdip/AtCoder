#include <stdio.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  printf("%d\n", 2 * n + 3);

  return 0;
}
