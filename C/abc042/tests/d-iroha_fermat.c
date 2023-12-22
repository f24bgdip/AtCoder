#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// 累乗計算（モジュラー演算付き）
long long mod_pow(long long x, long long y, long long mod) {
  long long res = 1;
  while (y > 0) {
    if (y & 1)
      res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}

// フェルマーの小定理を用いて、モジュラー逆元を計算
long long mod_inv(long long x, long long mod) {
  return mod_pow(x, mod - 2, mod);
}

int main() {
  long long inv;
  int k[] = {44443, 44444, 55554, 55555, 99999};

  for (int i = 0; i < 5; i++) {
    inv = mod_inv(k[i], MOD);
    printf("mod_inv(): i = %d, inv = %lld\n", i, inv);
  }

  return 0;
}