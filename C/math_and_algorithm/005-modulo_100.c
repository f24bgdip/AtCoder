#include <stdio.h>

#define MOD 100

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    if (scanf("%d", &a) != 1)
      return -1;
    ans += a % MOD;
  }
  printf("%d\n", ans % MOD);

  return 0;
}
