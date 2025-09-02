#include <bits/stdc++.h>
using namespace std;

int n, m1, m2; // 頂点数とグラフG、グラフHの辺の数
int f[10][10], g[10][10], a[10][10]; // f: グラフG, g: グラフH, a: コスト行列
int c[10], used[10],
    ans = 1e9; // c: 順列、used: DFSで使用するフラグ、ans: 最小コスト

// 現在の順列で最小コストを計算する関数
void check() {
  int now = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      now += (f[c[i]][c[j]] ^ g[i][j]) *
             a[i][j]; // fとgの辺の一致を確認してコスト加算
    }
  }
  ans = min(ans, now); // 最小コストを更新
}

// 順列を全探索するためのDFS関数
void dfs(int lv) {
  if (lv == n + 1) { // 順列が完成したらコスト計算
    check();
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (used[i])
      continue; // 既に使用されている頂点は飛ばす
    used[i] = 1;
    c[lv] = i;   // 頂点iを順列に追加
    dfs(lv + 1); // 次のレベルに進む
    used[i] = 0; // バックトラッキング
  }
}

int main() {
  cin >> n >> m1;
  // グラフGの入力
  for (int x, y, i = 1; i <= m1; ++i) {
    cin >> x >> y;
    f[x][y] = f[y][x] = 1;
  }

  cin >> m2;
  // グラフHの入力
  for (int x, y, i = 1; i <= m2; ++i) {
    cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }

  // コスト行列の入力
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  dfs(1);              // DFSによる全順列探索の開始
  cout << ans << endl; // 最小コストを出力
  return 0;
}
