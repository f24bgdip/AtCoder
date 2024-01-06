#include <stdio.h>

#define ll long long
#define MOD 1000000000

void matrix_multiply(ll matA[2][2], ll matB[2][2], ll res[2][2], ll mod) {
  ll temp[2][2] = {0};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        temp[i][j] = (temp[i][j] + matA[i][k] * matB[k][j]) % mod;
      }
    }
  }
  memcpy(res, temp, sizeof(temp));
}

// 繰り返し二乗法によるフィボナッチ数列の計算
ll fibonacci(ll n, ll mod) {
  ll fib[2][2] = {{1, 1}, {1, 0}};
  ll res[2][2] = {{1, 0}, {1, 1}};

  n -= 2;
  while (n > 0) {
    if (n % 2 == 1) {
      matrix_multiply(fib, res, res, mod);
    }
    matrix_multiply(fib, fib, fib, mod);
    n /= 2;
  }
  return res[0][0];
}

int main() {
  ll N;
  if (scanf("%lld", &N) != 1)
    return -1;

  ll result = fibonacci(N, MOD);
  printf("%lld\n", result);

  return 0;
}
