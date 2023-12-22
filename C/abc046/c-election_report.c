#include <stdio.h>

int main() {
  int N;
  long long T, A, votes_t, votes_a;

  if (scanf("%d", &N) != 1)
    return -1;

  if (scanf("%lld %lld", &votes_t, &votes_a) != 2)
    return -1;

  for (int i = 1; i < N; i++) {
    if (scanf("%lld %lld", &T, &A) != 2)
      return -1;

    long long times = (votes_t + T - 1) / T;
    if (times * A < votes_a) {
      times = (votes_a + A - 1) / A;
    }

    votes_t = times * T;
    votes_a = times * A;
  }

  printf("%lld\n", votes_t + votes_a);

  return 0;
}
