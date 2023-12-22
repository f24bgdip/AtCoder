#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  long long A[N + 1];
  for (int i = 1; i <= N; i++) {
    if (scanf("%lld", &A[i]) != 1)
      return -1;
  }

  int P[N + 1];
  for (int i = 2; i <= N; i++) {
    if (scanf("%d", &P[i]) != 1)
      return -1;
    if (P[i] == 1)
  }

  long long d[10];
  d[0] = A[1];
  for (int j = 1; j < 10; j++) {
    for (int i = 2; i <= N; i++) {
      A[P[i]] += A[i];
    }
    d[j] = d[j - 1] + A[1];
  }

  if (A[1] > 0) {
    printf("+\n");
  } else if (A[1] < 0) {
    printf("-\n");
  } else {
    printf("0\n");
  }

  return 0;
}
