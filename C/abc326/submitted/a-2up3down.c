#include <stdio.h>

int main(void) {
  int x, y;

  if (scanf("%d %d", &x, &y) != 2)
    return -1;

  int d = y - x;
  if ((d >= 0 && d <= 2) || (d <= 0 && d >= -3))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
