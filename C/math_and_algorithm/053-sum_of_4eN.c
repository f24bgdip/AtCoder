#include <stdio.h>

#define MOD 1000000007

// 繰り返し二乗法によるべき乗計算
long long mod_pow(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// モジュラー逆元を計算する
long long mod_inv(long long a, long long mod) {
  if (a < 0)
    a += mod;
  return mod_pow(a, mod - 2, mod);
}

int main() {
  long long N;
  if (scanf("%lld", &N) != 1)
    return -1;

  long long a = 1; // 初項は1
  long long r = 4; // 公比は4

  // 分子の計算: 1 - r^(N+1)
  long long numerator = 1 - mod_pow(r, N + 1, MOD);
  if (numerator < 0)
    numerator += MOD;
  numerator = a * numerator % MOD;

  // 分母の逆元の計算: 1 - r
  long long denominator_inv = mod_inv(1 - r, MOD);

  // 答えの計算: 分子に分母の逆元を掛けて、MOD で割った余りを求める
  long long answer = (numerator * denominator_inv) % MOD;

  printf("%lld\n", answer);
  return 0;
}
