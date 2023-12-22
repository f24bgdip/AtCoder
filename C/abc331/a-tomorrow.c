#include <stdio.h>

int main(void) {
  int M, D;
  if (scanf("%d %d", &M, &D) != 2)
    return -1;

  int y, m, d;
  if (scanf("%d %d %d", &y, &m, &d) != 3)
    return -1;

  d++;
  if (d > D) {
    d = 1;
    m++;
    if (m > M) {
      m = 1;
      y++;
    }
  }

  printf("%d %d %d\n", y, m, d);

  return 0;
}
