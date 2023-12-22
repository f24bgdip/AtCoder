// With respect for #1198938

#include <stdio.h>

int main() {
  int N;
  long long x;
  if (scanf("%d %lld", &N, &x) != 2)
    return -1;

  long long operation_count = 0;
  long long candy = 0;
  for (int i = 0; i < N; i++) {
    long long next_candy = 0;
    if (scanf("%lld", &next_candy) != 1)
      return -1;
    long long excess = (candy + next_candy) - x;
    if (excess > 0) {
      operation_count += excess;
      next_candy -= excess;
    }
    candy = next_candy;
  }

  printf("%lld\n", operation_count);

  return 0;
}
