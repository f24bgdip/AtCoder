#include <stdio.h>

int main(void) {
  int X, Y;
  if (scanf("%d %d", &X, &Y) != 2)
    return -1;

  int d = Y - X;
  // printf("d=%d\n", d);
  if (d > 2 || d < -3)
    printf("No\n");
  else
    printf("Yes\n");

  return 0;
}
