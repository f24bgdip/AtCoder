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
  int a, b;
  if (scanf("%d %d", &a, &b) != 2)
    return -1;

  printf("%d\n", gcd(a, b));

  return 0;
}
