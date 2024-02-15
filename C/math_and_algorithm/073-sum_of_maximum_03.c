// This code is based on #48685647.

#include <stdio.h>

#define MOD 1000000007

int main() {
  // 入力の読み取り
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 2のべき乗を事前計算
  long long power[N];
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = (2 * power[i - 1]) % MOD;
  }

  // 配列の宣言と入力の読み取り
  long long a[N];
  long long answer = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%llu", &a[i]) != 1)
      return -1;
    answer = (answer + power[i] * a[i]) % MOD;
  }
  printf("%llu\n", answer);

  return 0;
}
