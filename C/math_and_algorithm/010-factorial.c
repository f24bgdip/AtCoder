#include <stdio.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;
  long long factorial = 1;
  for (long long i = 2; i <= n; i++) {
    factorial *= i;
  }
  printf("%lld\n", factorial);

  return 0;
}
