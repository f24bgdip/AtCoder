#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 累積和の計算 (1からNへ)
  int A[N]; // 1ベース
  long long cumulative_sum[N];
  A[0] = 0;
  cumulative_sum[0] = 0;
  for (int i = 1; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
    cumulative_sum[i] = cumulative_sum[i - 1] + A[i];
  }

  // 総移動距離の計算
  int M;
  if (scanf("%d", &M) != 1)
    return -1;
  int start, end;
  if (scanf("%d", &start) != 1)
    return -1;
  long long total = 0;
  for (int i = 1; i < M; i++) {
    if (scanf("%d", &end) != 1)
      return -1;
    if (start < end) { // 1からNへの方向
      total += cumulative_sum[end - 1] - cumulative_sum[start - 1];
    } else { // Nから1への方向
      total += cumulative_sum[start - 1] - cumulative_sum[end - 1];
    }
    start = end;
  }

  printf("%lld\n", total);
  return 0;
}
