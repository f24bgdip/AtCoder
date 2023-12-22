#include <stdio.h>

int main(void) {
  int a[3];

  if (scanf("%d %d %d", &a[0], &a[1], &a[2]) != 3)
    return -1;

  printf("%d\n", a[0] + a[1] + a[2]);

  return 0;
}
