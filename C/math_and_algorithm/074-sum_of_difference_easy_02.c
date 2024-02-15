#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  long long sum = 0;
  for (int i = 1; i <= N; i++) {
    int A;
    if (scanf("%d", &A) != 1)
      return -1;

    long long coefficient = -(N - (2 * i - 1));
    sum += coefficient * A;
  }
  printf("%lld\n", sum);

  return 0;
}
