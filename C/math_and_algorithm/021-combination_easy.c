#include <stdio.h>

long long combination(int n, int r) {
  // nCr = nC(n-r)
  if (r > n - r)
    r = n - r;

  long long ans = 1;
  int i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }

  return ans;
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  printf("%lld\n", combination(n, r));
  return 0;
}
