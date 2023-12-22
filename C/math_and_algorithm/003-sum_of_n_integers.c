#include <stdio.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    if (scanf("%d", &a) != 1)
      return -1;
    sum += a;
  }
  printf("%d\n", sum);

  return 0;
}
