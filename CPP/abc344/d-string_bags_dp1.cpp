#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string T;
  cin >> T;

  int N;
  cin >> N;

  vector<vector<pair<int, int>>> bags(
      N); // bags[i]: 袋iの文字列とコストのペアのリスト

  // 入力を受け取り、各袋の内容を bags に格納する
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    bags[i].resize(A);
    for (int j = 0; j < A; ++j) {
      string str;
      cin >> str;
      int cost = str.size();       // 文字列の長さをコストとする
      bags[i][j] = {cost, str[0]}; // {コスト, 文字} のペアを格納
    }
  }

  int targetLength = T.size();
  vector<int> dp(targetLength + 1,
                 INT_MAX); // dp[i]: 長さiの文字列を作るのに必要な最小コスト

  // 初期条件: 長さ0の文字列を作るのに必要なコストは0
  dp[0] = 0;

  // 動的計画法の更新
  for (int i = 0; i <= targetLength; ++i) {
    for (int j = 0; j < N; ++j) {
      for (const auto &pair : bags[j]) {
        int cost = pair.first;
        char c = pair.second;
        if (i >= cost && dp[i - cost] != INT_MAX) {
          // i - cost の長さの文字列を作ることができる場合
          // dp[i] を更新する
          dp[i] = min(dp[i], dp[i - cost] + (T[i - cost] == c ? 0 : 1));
        }
      }
    }
  }

  // 最終的な答えを出力
  int answer = dp[targetLength] == INT_MAX ? -1 : dp[targetLength];
  cout << answer << endl;

  return 0;
}
