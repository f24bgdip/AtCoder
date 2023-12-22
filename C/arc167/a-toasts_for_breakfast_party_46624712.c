#include <stdio.h>

void merge_sort(int n, int x[]) {
  static int y[200001] = {};
  if (n <= 1)
    return;
  merge_sort(n / 2, &(x[0]));
  merge_sort((n + 1) / 2, &(x[n / 2]));

  int i, p, q;
  for (i = 0, p = 0, q = n / 2; i < n; i++) {
    if (p >= n / 2)
      y[i] = x[q++];
    else if (q >= n)
      y[i] = x[p++];
    else
      y[i] = (x[p] < x[q]) ? x[p++] : x[q++];
  }
  for (i = 0; i < n; i++)
    x[i] = y[i];
}

int main() {
  int i, N, M, A[200001];
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; i++)
    scanf("%d", &(A[i]));
  merge_sort(N, A);

  int j;
  long long ans = 0;
  while (N != M * 2) {
    N--;
    M--;
    ans += (long long)A[N] * A[N];
  }
  for (i = 0, j = N - 1; i < j; i++, j--)
    ans += (long long)(A[i] + A[j]) * (A[i] + A[j]);
  printf("%lld\n", ans);
  fflush(stdout);
  return 0;
}