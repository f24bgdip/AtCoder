#include <stdio.h>

int main() {
  int a, b, c, count = 1;

  if (scanf("%d %d %d", &a, &b, &c) != 3)
    return -1;

  if (a != b) {
    count++;
  }

  if (a != c && b != c) {
    count++;
  }

  printf("%d\n", count);

  return 0;
}
