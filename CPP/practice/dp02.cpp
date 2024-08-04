#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int N, W;
std::unordered_map<std::string, int> dp;

// メモ化のキーを生成する関数
std::string make_key(int n, int W) {
  return std::to_string(n) + "," + std::to_string(W);
}

// メモ化のチェックを行う関数
bool memoized_result(const std::string &key, int &result) {
  if (dp.find(key) != dp.end()) {
    result = dp[key];
    return true;
  }
  return false;
}

int recursive(int n, int w, const std::vector<int> &x,
              const std::vector<int> &y) {
  // ベースケース
  if (N == 0 || W == 0)
    return 0;

  std::string key = make_key(n, w);

  // メモ化のチェック
  int result;
  if (memoized_result(key, result))
    return result;

  // アイテムを選ばない場合
  int exclude = recursive(n - 1, w, x, y);

  // アイテムを選ぶ場合
  int include = 0;
  if (w >= x[n - 1]) {
    include = y[n - 1] + recursive(n - 1, w - x[n - 1], x, y);
  }

  // 最大値をメモ化
  result = std::max(exclude, include);
  dp[key] = result;

  return result;
}

int main() {
  std::cin >> N >> W;

  std::vector<int> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x[i] >> y[i];
  }

  int ret = recursive(N, W, x, y);
  std::cout << ret << std::endl;

  return 0;
}
