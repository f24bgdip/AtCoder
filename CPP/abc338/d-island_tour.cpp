#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int n, m;
int x[N], diffArray[N];

void add(int l, int r, int v) {
  diffArray[l] += v;
  diffArray[r + 1] -= v;
}

void work(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  int dist_direct = b - a;
  int dist_reverse = n - dist_direct;
  int dist_min = min(dist_direct, dist_reverse);

  add(1, n, dist_min);
  if (dist_direct < dist_reverse) {
    add(a + 1, b, dist_reverse - dist_direct);
  } else {
    add(1, a, dist_direct - dist_reverse);
    add(b + 1, n, dist_direct - dist_reverse);
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i];
  }

  for (int i = 1; i < m; i++) {
    work(x[i], x[i + 1]);
  }

  int ans = LLONG_MAX;
  int cumulativeCost = 0;
  for (int i = 1; i <= n; i++) {
    cumulativeCost += diffArray[i];
    ans = min(ans, cumulativeCost);
  }

  cout << ans << endl;
  return 0;
}
