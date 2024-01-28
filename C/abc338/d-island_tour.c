#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

void add(int n, ll diff[n], int l, int r, ll v) {
  diff[l] += v;
  diff[r + 1] -= v;
}

void work(int n, ll diff[n], ll a, ll b) {
  if (a > b) {
    ll temp = a;
    a = b;
    b = temp;
  }
  ll dist_direct = b - a;
  ll dist_reverse = n - dist_direct;
  ll dist_min = min(dist_direct, dist_reverse);

  add(n, diff, 1, n, dist_min);
  if (dist_direct < dist_reverse) {
    add(n, diff, a + 1, b, dist_reverse - dist_direct);
  } else {
    add(n, diff, 1, a, dist_direct - dist_reverse);
    add(n, diff, b + 1, n, dist_direct - dist_reverse);
  }
}

int main() {
  ll N, M;
  if (scanf("%lld %lld", &N, &M) != 2)
    return -1;

  ll x[N], diff[N] = {0};
  for (ll i = 1; i <= M; i++) {
    if (scanf("%lld", &x[i]) != 1)
      return -1;
  }

  for (ll i = 1; i < M; i++) {
    work(diff, N, x[i], x[i + 1]);
  }

  ll ans = LLONG_MAX;
  ll cumulativeCost = 0;
  for (ll i = 1; i <= N; i++) {
    cumulativeCost += diff[i];
    ans = min(cumulativeCost, ans);
  }

  printf("%lld\n", ans);
  return 0;
}
