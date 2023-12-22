#include <stdio.h>

int main() {
  int N;
  long long x;
  if (scanf("%d %lld", &N, &x) != 2)
    return -1;

  long long candies[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%lld", &candies[i]) != 1)
      return -1;
  }

  long long operation_count = 0;
  for (int i = 0; i < N - 1; i++) {
    long long excess = (candies[i] + candies[i + 1]) - x;
    if (excess > 0) {
      operation_count += excess;
      candies[i + 1] -= excess;
    }
  }

  printf("%lld\n", operation_count);

  return 0;
}
