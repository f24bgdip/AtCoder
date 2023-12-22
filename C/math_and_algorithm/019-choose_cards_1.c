#include <stdio.h>

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  long long count[3] = {0};
  for (int i = 0; i < n; i++) {
    int color;
    if (scanf("%d", &color) != 1)
      return -1;
    count[color - 1]++;
  }

  long long ways = 0;
  for (int i = 0; i < 3; i++)
    ways += count[i] * (count[i] - 1) / 2;

  printf("%lld\n", ways);

  return 0;
}
