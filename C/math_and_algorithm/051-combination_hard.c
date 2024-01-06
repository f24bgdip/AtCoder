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

// 階乗の計算
long long factorial(long long n) {
  long long result = 1;
  for (long long i = 2; i <= n; i++) {
    result = (result * i) % MOD;
  }
  return result;
}

int main() {
  long long X, Y;
  if (scanf("%lld %lld", &X, &Y) != 2)
    return -1;

  // アプローチ
  // X + Y の移動のうち、X 回を右に移動する場合の組み合わせの数が求める答え
  // 組み合わせ数は (X+Y)! / (X! * Y!) と表せるが、
  // モジュラー算術では、分母の逆元を乗算する。
  // すなわち、(X+Y)! * (X! の逆元) * (Y! の逆元) mod MOD が答えとなる。

  long long factorial_XY = factorial(X + Y);
  // X! を計算し、MOD 1000000007 での余りを求める
  long long factorial_X = factorial(X);
  // Y! を計算し、MOD 1000000007 での余りを求める
  long long factorial_Y = factorial(Y);

  // X! の逆元を計算する。フェルマーの小定理を使用して、
  // X!^(MOD - 2) mod MOD を計算し、これが X! の逆元となる
  long long inverse_factorial_X = mod_pow(factorial_X, MOD - 2, MOD);

  // Y! の逆元を計算する。フェルマーの小定理を使用して、
  // Y!^(MOD - 2) mod MOD を計算し、これが Y! の逆元となる
  long long inverse_factorial_Y = mod_pow(factorial_Y, MOD - 2, MOD);

  // (X + Y)! を計算し、MOD 1000000007 での余りを求める。
  long long answer =
      (((factorial_XY * inverse_factorial_X) % MOD) * inverse_factorial_Y) %
      MOD;

  printf("%lld\n", answer);

  return 0;
}
