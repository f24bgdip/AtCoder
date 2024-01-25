#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long ll;
const ll INF = 1e18; // 定義する最大値（無限大の代用）

int main() {
  ll N, K;
  cin >> N >> K;
  // 点を格納する配列
  vector<pair<ll, ll>> points(N);

  // 最小のx座標、y座標
  ll minX = INF, minY = INF;
  // 点の入力
  for (ll i = 0; i < N; ++i) {
    cin >> points[i].first >> points[i].second;
    minX = min(minX, points[i].first);
    minY = min(minY, points[i].second);
  }

  // 座標の正規化
  for (ll i = 0; i < N; ++i) {
    points[i].first -= minX;
    points[i].second -= minY;
  }

  // 点をx座標に基づいてソート
  sort(points.begin(), points.end());

  // 最小面積の初期化
  ll answer = std::numeric_limits<long long>::max();
  // すべてのx座標のペアに対してループ
  for (ll i = 0; i < N; ++i)
    for (ll j = i + K - 1; j < N; ++j) {
      // y座標の値を格納するためのベクトル
      vector<ll> y_values;
      // 選択されたx座標の範囲内の点のy座標を集める
      for (ll k = i; k <= j; ++k)
        y_values.push_back(points[k].second);

      // y座標をソート
      sort(y_values.begin(), y_values.end());

      // y座標のペアに対してループし、最小面積を計算
      for (ll y = 0; y <= y_values.size() - K; ++y) {
        ll width = points[j].first - points[i].first;  // 長方形の幅
        ll height = y_values[y + K - 1] - y_values[y]; // 長方形の高さ

        // オーバーフローの可能性をチェック
        if (width <= std::numeric_limits<long long>::max() / height) {
          ll area = width * height;
          answer = min(answer, area);
        }
      }
    }

  cout << answer << endl;
  return 0;
}
