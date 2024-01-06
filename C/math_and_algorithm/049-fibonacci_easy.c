#include <stdio.h>

#define MOD 1000000007

int main() {
  int N;
  scanf("%d", &N);

  if (N == 1 || N == 2) {
    printf("1\n");
    return 0;
  }

  long long a = 1, b = 1, c;
  for (int i = 3; i <= N; i++) {
    // fibonacci: a[n]=a[n-1]+a[n-2]
    c = (a + b) % MOD;
    a = b;
    b = c;
  }

  printf("%lld\n", c);
  return 0;
}
