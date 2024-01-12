// This code is based on #29136636

#include <stdio.h>

typedef long long ll;

int main(void) {
  ll N, K;
  // NとKの値を入力
  if (scanf("%lld %lld", &N, &K) != 2)
    return -1;

  // 全体の組み合わせ数を計算 (N^3)
  ll totalCombinations = N * N * N;
  // 条件を満たさない組み合わせの数を初期化
  ll invalidCombinations = K * (K - 1) * (3 * N - 2 * K + 1);
  printf("invalidCombinations = %lld\n", invalidCombinations);
  // 条件を満たす組み合わせの数を計算
  ll validCombinations = totalCombinations - N - invalidCombinations;

  printf("%lld\n", validCombinations);

  return 0;
}
