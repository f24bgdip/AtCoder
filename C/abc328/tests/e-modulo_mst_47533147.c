#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define rng(i, a, b) for (int i = int(a); i <= int(b); i++)
#define per(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define gnr(i, a, b) for (int i = int(b); i >= int(a); i--)
#define vint vector<int>
#define ll long long
using namespace std;

vector<pair<int, ll>> edges[10];
ll n, m, k;
ll ans = LLONG_MAX;
int fa[10];

int find(int x) {
  if (fa[x] == x)
    return x;
  else
    return find(fa[x]);
}

void dfs(int node, ll sum) {
  if (node == n) {
    ans = min(ans, sum);
    return;
  }
  for (auto p : edges[node]) {
    int t1 = find(node), t2 = find(p.first);
    if (t1 != t2) {
      int temp = fa[t1];
      fa[t1] = t2;

      cout << "u: " << node << " v: " << p.first << " weight: " << p.second
           << endl;
      dfs(node + 1, (sum + p.second) % k);
      cout << " ans: " << ans << " sum: " << sum << endl;

      fa[t1] = temp;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  rng(i, 1, n) fa[i] = i;

  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  dfs(1, 0);
  cout << ans << endl;
  return 0;
}