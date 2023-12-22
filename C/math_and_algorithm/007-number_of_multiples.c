#include <stdio.h>

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main(void) {
  int n = 0, x = 0, y = 0;
  if (scanf("%d %d %d", &n, &x, &y) != 3)
    return -1;

  int count = 0;
  count += (int)(n / x);
  count += (int)(n / y);
  count -= (int)(n / (x / gcd(x, y) * y));
  printf("%d\n", count);

  return 0;
}
