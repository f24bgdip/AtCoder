#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  long long diff = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      diff += A[j] - A[i];
    }
  }
  printf("%lld\n", diff);

  return 0;
}
