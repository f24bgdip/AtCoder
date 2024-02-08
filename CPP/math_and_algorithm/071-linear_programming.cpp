#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// 制約条件を満たすかを判定する関数
bool isValid(const vector<int> &a, const vector<int> &b, const vector<int> &c,
             int n, double k) {
  // 下限と上限の初期化
  double lb = 0, ub = k;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      // a[i] > b[i] の場合の上限を更新
      // 制約式 a[i]x + b[i]y ≤ c[i] から x の最大値を計算
      ub = min(ub, (c[i] - b[i] * k) / (double)(a[i] - b[i]));
    } else if (a[i] < b[i]) {
      // a[i] < b[i] の場合の下限を更新
      // 制約式 a[i]x + b[i]y ≤ c[i] から x の最小値を計算
      lb = max(lb, (b[i] * k - c[i]) / (double)(b[i] - a[i]));
    } else if (c[i] < b[i] * k) {
      // a[i] = b[i] の場合で、制約を満たさない場合
      // 制約式 a[i]x + b[i]y = c[i] が k に対して成立しない場合は偽を返す
      return false;
    }
  }
  // lb（下限）と ub（上限）が矛盾しない場合、制約を満たす
  return lb <= ub;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // 探索範囲の初期化
  double lb = 0, ub = 1e9;
  // バイナリ検索
  for (int i = 0; i < 100; ++i) {
    double mid = (lb + ub) / 2;
    if (isValid(a, b, c, n, mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  cout << fixed << setprecision(15) << lb << endl;
  return 0;
}
