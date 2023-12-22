#pragma GCC optimize("O3")
#pragma GCC target("avx")
// #include<bits/stdc++.h>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
inline char getcha() {
  if (ci - cn == cm) {
    fread_unlocked(cn, 1, cm, stdin);
    ci = cn;
  }
  return *ci++;
}

inline int getint() {
  int A = 0;
  if (ci - cn + 16 > cm)
    while ((ct = getcha()) >= '0')
      A = A * 10 + ct - '0';
  else
    while ((ct = *ci++) >= '0')
      A = A * 10 + ct - '0';
  return A;
}

ll zenbu[900000];
ll tmp[900001];

void pakuri_sort(int N, ll A[]) {
  const int b = 16;
  rep(k, 4) {
    int kazu[1 << b] = {}, kazu2[1 << b] = {};
    rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;
    rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];
    for (int i = N - 1; i >= 0; i--)
      tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];
    k++;
    rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;
    rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];
    for (int i = N - 1; i >= 0; i--)
      A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];
  }
}

int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(false);

  int H = getint(), W = getint(), N = getint();
  int k = 0;
  rep(i, N) {
    int a = getint(), b = getint();
    for (int i = max(2, a - 1); i <= min(H - 1, a + 1); i++) {
      for (int j = max(2, b - 1); j <= min(W - 1, b + 1); j++) {
        zenbu[k++] = ((ll)i << 30) + j;
      }
    }
  }

  pakuri_sort(k, zenbu);

  ll kotae[10] = {};
  int total = -1;
  ll mae = -1;
  int kazu = 0;
  rep(i, k) {
    if (mae == zenbu[i])
      kazu++;
    else {
      kotae[kazu]++;
      total++;
      mae = zenbu[i];
      kazu = 1;
    }
  }
  kotae[kazu]++;
  total++;
  kotae[0] = (ll)(H - 2) * (W - 2) - total;

  rep(i, 10) printf("%lld\n", kotae[i]);

  Would you please return 0;
}