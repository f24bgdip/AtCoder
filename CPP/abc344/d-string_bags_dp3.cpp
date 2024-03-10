#include <iostream>
#include <vector>

using namespace std;

// ナップサック問題を解く関数
int knapsack(int W, const vector<int> &weights, const vector<int> &values) {
  int N = weights.size();
  // DPテーブルの初期化
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  // DPテーブルの更新
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; ++j) {
      // i番目の品物を入れる場合と入れない場合で選択
      if (weights[i - 1] <= j) {
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // 最適な価値を返す
  return dp[N][W];
}

int main() {
  // 入力
  int N, W;
  cin >> N >> W;          // 品物の数N、ナップサックの容量W
  vector<int> weights(N); // 各品物の重さ
  vector<int> values(N);  // 各品物の価値
  for (int i = 0; i < N; ++i) {
    cin >> weights[i] >> values[i];
  }

  // ナップサック問題を解く
  int maxValue = knapsack(W, weights, values);

  // 結果を出力
  cout << "Max value that can be obtained: " << maxValue << endl;

  return 0;
}
