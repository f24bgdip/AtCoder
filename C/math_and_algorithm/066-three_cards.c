#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int main(void) {
  int N, K;
  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  long long total_combinations = N * N * N;
  // すべてのカードが同じ数値を持つ組み合わせ（N通り）
  long long invalid_combinations = N;
  // K未満の組み合わせ
  for (int i = 1; i <= N; i++) {
    invalid_combinations += min(N, i + K - 1) - max(1, i - K + 1) + 1;
  }
  printf("invalid_combinations = %lld\n", invalid_combinations);

  total_combinations -= invalid_combinations;
  printf("total_combinations = %lld\n", total_combinations);

  return 0;
}
