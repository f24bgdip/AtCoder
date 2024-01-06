#include <stdio.h>

#define MOD 1000000007

// 繰り返し二乗法によるべき乗計算
// example 2^15
// b=15=0x1111
// 0x1000 は、result=result*a*a*a*a*a*a*a*a
// 0x0100 は、result=result*a*a*a*a
// 0x0010 は、result=result*a*a
// 0x0001 は、result=result*a
// 15回の計算を4回の計算で行える
long long mod_pow(long long a, long long b) {
  long long result = 1;
  // 以降の計算でオーバーフローを防ぐため、aをMODで割った余りを使用する
  a = a % MOD;
  while (b > 0) {
    // bの最下位ビットが1の場合
    if (b % 2 == 1)
      // 現在のaを結果に掛け、MODで割った余りを取る
      result = (result * a) % MOD;
    // aを二乗し、MODで割った余りを次の計算に使用
    a = (a * a) % MOD;
    // bを2で割る（右シフト）。これにより、bのビットを順に処理する
    b /= 2;
  }
  return result;
}

int main(void) {
  long long a, b;
  if (scanf("%lld %lld", &a, &b) != 2)
    return -1;

  printf("%lld\n", mod_pow(a, b));

  return 0;
}
