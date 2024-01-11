#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
long long int llmin(long long int a, long long int b) {
  return (a < b) ? a : b;
}
long long int llmax(long long int a, long long int b) {
  return (a > b) ? a : b;
}

long long int_pow(int b, int e) {
  long long r = 1;
  for (int i = 0; i < e; ++i) {
    if (LLONG_MAX / r < b)
      return LLONG_MAX;
    r *= b;
  }
  return r;
}

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

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int N, S;
  if (scanf("%d %d", &N, &S) != 2)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  char S[100 + 1];
  if (scanf("%s", S) != 1)
    return -1;

  printf("%d\n", N);
  printf("%lld\n", dp[N - 1]);
  printf("%s\n", S);
  printf("%c\n", S[0]);

  return 0;
}
