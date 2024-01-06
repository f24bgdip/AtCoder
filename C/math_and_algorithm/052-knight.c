#include <stdio.h>

#define MOD 1000000007

// 繰り返し二乗法によるべき乗計算
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
  return mod_pow(a, mod - 2, mod);
}

// nCr のモジュラー計算
long long nCr_mod(long long n, long long r) {
  // 組み合わせが定義されない場合（r > n）は0を返す
  if (r > n)
    return 0;
  // 分子（numerator）と分母（denominator）を初期化
  long long numerator = 1, denominator = 1;
  // 分子と分母を計算するためのループ
  for (long long i = 1; i <= r; i++) {
    // 分子は nCr の計算において n*(n-1)*...*(n-r+1) の部分
    numerator = (numerator * (n - r + i)) % MOD;
    // 分母は r! （rの階乗）の部分
    denominator = (denominator * i) % MOD;
  }
  // 分子に分母の逆元を掛けることで nCr の計算を行い、
  // 結果を MOD で割った余りを返す
  return (numerator * mod_inv(denominator, MOD)) % MOD;
}

int main() {
  long long X, Y;
  if (scanf("%lld %lld", &X, &Y) != 2)
    return -1;

  // ナイトが (X, Y) に到達することが可能かどうかを判断する条件
  if ((X + Y) % 3 != 0 || 2 * X < Y || 2 * Y < X) {
    // ナイトの移動パターンにより、(X + Y) の合計が 3 の倍数でなければならず、
    // X と Y は特定の範囲内に収まる必要がある。
    // これらの条件を満たさない場合、(X, Y) に到達する経路は存在しない。
    printf("0\n");
  } else {
    // ナイトが (X, Y) に到達するために必要な移動回数を計算
    // 全体の移動回数 (n) と、そのうちの特定の移動パターンの回数 (r) を計算
    long long n = (X + Y) / 3;
    long long r = (2 * Y - X) / 3;
    // n と r を用いて、組み合わせの計算を行い、
    // (X, Y) に到達するための経路の総数を出力
    printf("%lld\n", nCr_mod(n, r));
  }
  return 0;
}