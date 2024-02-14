#include <stdio.h>

typedef long long ll;

ll solve(ll N) {
  if (N == 1)
    return 0;

  ll payment = N;
  ll a1 = N / 2;
  ll a2 = a1 + N % 2;
  payment += solve(a1);
  payment += solve(a2);
  return payment;
}

int main() {
  ll N;
  if (scanf("%lld", &N) != 1)
    return -1;
  ll result = solve(N);
  printf("%lld\n", result);

  return 0;
}
