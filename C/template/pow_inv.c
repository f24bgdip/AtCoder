#include <stdio.h>

#define MOD 1000000007

// 繰り返し二乗法によるべき乗計算
// example a^b=2^15の場合
// b=15=0x1111
// 0x1000 は、result=result*a*a*a*a*a*a*a*a
// 0x0100 は、result=result*a*a*a*a
// 0x0010 は、result=result*a*a
// 0x0001 は、result=result*a
// 15回の計算を4回の計算で行える
long long mod_pow(long long base, long long exp, long long mod) {
  long long result = 1;
  // 以降の計算でオーバーフローを防ぐため、aをMODで割った余りを使用する
  base = base % mod;
  while (exp > 0) {
    // bの最下位ビットが1の場合
    if (exp % 2 == 1) {
      // 現在のbaseを結果に掛け、MODで割った余りを取る
      result = (result * base) % mod;
    }
    // baseを二乗し、MODで割った余りを次の計算に使用
    base = (base * base) % mod;
    // bを2で割る（右シフト）。これにより、bのビットを順に処理する
    exp /= 2;
  }
  return result;
}

// モジュラー逆元を計算する
long long mod_inv(long long a, long long mod) {
  if (a < 0)
    // 負の数の場合、正の同等値に変換
    a += mod;
  return mod_pow(a, mod - 2, mod);
}

int main(void) {
  long long a, b;
  if (scanf("%lld %lld", &a, &b) != 2)
    return -1;

  printf("%lld\n", mod_pow(a, b, MOD));

  return 0;
}
