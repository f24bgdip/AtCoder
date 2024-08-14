#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> p(q);
  vector<int> v(q);
  vector<int> max_p(n, 0); // 位置ごとの最大値を保持
  int max_v = 0;           // 現在までの最大値
  long long dp = 1;        // 操作列の組み合わせ数

  for (int i = 0; i < q; ++i) {
    cin >> p[i] >> v[i];
    --p[i]; // 0-indexed に調整

    // 過去の最大値よりも大きい値が来た場合、操作は無効
    if (v[i] < max_v) {
      cout << "0\n";
      return 0;
    }

    // 現在の位置までの最大値を追跡
    if (v[i] > max_p[p[i]]) {
      max_p[p[i]] = v[i];
    } else {
      cout << "0\n";
      return 0;
    }

    // 更新された最大値を記録
    max_v = max(max_v, v[i]);

    // 有効な操作列の組み合わせ数を更新
    if (i > 0 && v[i] >= max_v) {
      dp = (dp * 2) % MOD;
    }
  }

  cout << dp << "\n";
  return 0;
}
