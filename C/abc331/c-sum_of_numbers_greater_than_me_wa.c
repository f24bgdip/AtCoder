#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Expansioned_A;

int compare(const void *a, const void *b) {
  return ((Expansioned_A *)a)->value - ((Expansioned_A *)b)->value;
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  Expansioned_A ex_A[N];
  long long sum = 0;

  for (int i = 0; i < N; i++) {
    if (scanf("%d", &ex_A[i].value) != 1)
      return -1;
    ex_A[i].index = i;
    sum += ex_A[i].value;
  }

  qsort(ex_A, N, sizeof(Expansioned_A), compare);

  long long cumulative_sum[N + 1];
  cumulative_sum[0] = 0;
  for (int i = 0; i < N; i++) {
    cumulative_sum[i + 1] = cumulative_sum[i] + ex_A[i].value;
  }

  for (int i = 0; i < N; i++) {
    long long ans = 0;
    for (int j = 0; j < N; j++) {
      if (ex_A[j].index == i) {
        ans = sum - cumulative_sum[j + 1];
        break;
      }
    }
    printf("%lld ", ans);
  }

  return 0;
}
