#include <stdio.h>

#define MOD 1000000007

typedef long long ll;

// モジュラス MOD における2のn乗を計算する関数
ll mod_pow(ll base, int exp, ll modulus) {
  ll result = 1;
  base = base % modulus;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exp = exp >> 1;
  }
  return result;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll A;
    if (scanf("%lld", &A) != 1)
      return -1;
    ll multiplier = mod_pow(2, i, MOD);
    ll add = (A * multiplier) % MOD;
    sum = (sum + add) % MOD;

    // デバッグ出力
    printf("A[%d] = %lld, multiplier = %lld, add = %lld, current sum = %lld\n",
           i, A, multiplier, add, sum);
  }

  printf("%lld\n", sum);

  return 0;
}
