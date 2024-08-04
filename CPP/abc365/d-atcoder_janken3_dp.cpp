#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Aの手に対して負けないBの手を設定する関数
char getNotLoseHand(char c, char last) {
  if (c == 'R') {
    if (last != 'P')
      return 'P';
    else
      return 'R';
  }
  if (c == 'P') {
    if (last != 'S')
      return 'S';
    else
      return 'P';
  }
  // if (c == 'S')
  if (last != 'R')
    return 'R';
  else
    return 'S';
}

int main() {
  int N;
  cin >> N;
  string text;
  cin >> text;

  vector<vector<int>> dp(N, vector<int>(3, 0));
  vector<vector<int>> choice(N, vector<int>(3, -1)); // Bの手を記録

  // 最初の手に対して負けない手を設定
  for (int j = 0; j < 3; ++j) {
    char lastHand = (j == 0) ? 'R' : (j == 1) ? 'P' : 'S';
    char firstHand = getNotLoseHand(text[0], '\0');
    int firstHandIndex = (firstHand == 'R') ? 0 : (firstHand == 'P') ? 1 : 2;
    dp[0][firstHandIndex] = (firstHand == lastHand) ? 0 : 1;
    choice[0][firstHandIndex] = firstHandIndex;
  }

  // 動的計画法によるDPテーブルの構築
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      char lastHand = (j == 0) ? 'R' : (j == 1) ? 'P' : 'S';
      char currentHand = getNotLoseHand(text[i], lastHand);
      int currentHandIndex = (currentHand == 'R')   ? 0
                             : (currentHand == 'P') ? 1
                                                    : 2;

      for (int k = 0; k < 3; ++k) {
        if (currentHandIndex != k) {
          int winCount =
              dp[i - 1][k] + ((currentHand == 'R' && text[i] == 'S') ||
                                      (currentHand == 'P' && text[i] == 'R') ||
                                      (currentHand == 'S' && text[i] == 'P')
                                  ? 1
                                  : 0);
          if (winCount > dp[i][currentHandIndex]) {
            dp[i][currentHandIndex] = winCount;
            choice[i][currentHandIndex] = k;
          }
        } else {
          int winCount = dp[i - 1][k];
          if (winCount > dp[i][currentHandIndex]) {
            dp[i][currentHandIndex] = winCount;
            choice[i][currentHandIndex] = k;
          }
        }
      }
    }
  }

  // Bさんの最大勝利回数を取得
  int result = max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
  cout << result << endl;

  // Bさんの手を出力
  int last_choice = -1;
  if (dp[N - 1][0] >= dp[N - 1][1] && dp[N - 1][0] >= dp[N - 1][2]) {
    last_choice = 0;
  } else if (dp[N - 1][1] >= dp[N - 1][0] && dp[N - 1][1] >= dp[N - 1][2]) {
    last_choice = 1;
  } else {
    last_choice = 2;
  }

  vector<char> b_hand(N);
  for (int i = N - 1; i >= 0; --i) {
    if (last_choice == 0) {
      b_hand[i] = 'R';
    } else if (last_choice == 1) {
      b_hand[i] = 'P';
    } else {
      b_hand[i] = 'S';
    }
    last_choice = choice[i][last_choice];
  }

  for (char hand : b_hand) {
    cout << hand;
  }
  cout << endl;

  return 0;
}
