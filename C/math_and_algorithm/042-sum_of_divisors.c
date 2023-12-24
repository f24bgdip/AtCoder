#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  long long *divisor_count = (long long *)malloc((N + 1) * sizeof(long long));
  for (int i = 1; i <= N; i++) {
    divisor_count[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      divisor_count[j]++;
    }
  }

  long long total = 0;
  for (int i = 1; i <= N; i++) {
    total += (long long)i * divisor_count[i];
  }

  printf("%lld\n", total);

  free(divisor_count);
  return 0;
}
