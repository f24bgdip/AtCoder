#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *upper_bound(int *first, int *last, int value) {
  int *it;
  int count, step;
  count = last - first;

  while (count > 0) {
    it = first;
    step = count / 2;
    it += step;
    if (!(value < *it)) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N], sortedA[N];
  long long sum = 0;

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    sortedA[i] = A[i];
    sum += A[i];
  }

  qsort(sortedA, N, sizeof(int), compare);

  long long cumulative_sum[N + 1];
  cumulative_sum[0] = 0;

  for (int i = 0; i < N; i++) {
    cumulative_sum[i + 1] = cumulative_sum[i] + sortedA[i];
  }

  for (int i = 0; i < N; i++) {
    int *upper = upper_bound(sortedA, sortedA + N, A[i]);
    long long ans = sum - cumulative_sum[upper - sortedA];
    printf("%lld ", ans);
  }

  return 0;
}
