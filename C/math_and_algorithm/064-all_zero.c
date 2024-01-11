#include <stdio.h>

int main(void) {
  int N, K;
  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int A;
    if (scanf("%d", &A) != 1)
      return -1;
    sum += A;
  }

  if (sum <= K && (K - sum) % 2 == 0)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
