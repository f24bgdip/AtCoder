#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  long long sum;
  int num;
} CUMULATIVE;

int cmp_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int search(CUMULATIVE *st, int l, int r, long long x) {
  int best = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (st[m].sum <= x) {
      best = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return best;
}

int main() {

  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  int R[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &R[i]) != 1)
      return -1;
  }

  qsort(R, N, sizeof(int), cmp_int);

  CUMULATIVE cumulative[N];
  memset(cumulative, 0, sizeof(cumulative));

  cumulative[0].sum = R[0];
  cumulative[0].num = 1;
  for (int i = 1; i < N; i++) {
    cumulative[i].sum += cumulative[i - 1].sum + R[i];
    cumulative[i].num = i + 1;
  }

  for (int i = 0; i < Q; i++) {
    long long query;
    if (scanf("%lld", &query) != 1)
      return -1;

    int m = search(cumulative, 0, N - 1, query);
    if (m != -1)
      printf("%d\n", cumulative[m].num);
    else
      printf("0\n");
  }

  return 0;
}
