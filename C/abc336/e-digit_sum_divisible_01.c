#include <stdio.h>

int digit_sum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  long long count = 0;
  for (int i = 1; i <= N; i++) {
    if (i % digit_sum(i) == 0) {
      count++;
    }
  }

  printf("%lld\n", count);
  return 0;
}
