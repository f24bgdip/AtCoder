#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
ll int ll_min(ll int a, ll int b) { return (a < b) ? a : b; }
ll int ll_max(ll int a, ll int b) { return (a > b) ? a : b; }

ll int_pow(int base, int exp) {
  ll result = 1;
  for (int i = 0; i < exp; ++i) {
    if (LLONG_MAX / result < base) {
      return LLONG_MAX;
    }
    result *= base;
  }
  return result;
}

// 繰り返し二乗法によるべき乗計算
ll mod_pow(ll base, ll exp, ll mod) {
  ll result = 1;
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
