#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<vector<int>> dp(N, vector<int>(N, 0));

  // 初期化
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 1;
  }

  // 長さ2の区間を初期化
  for (int i = 0; i < N - 1; ++i) {
    dp[i][i + 1] = 1;
  }

  // DPの更新
  for (int length = 2; length < N; ++length) {
    for (int i = 0; i + length < N; ++i) {
      int j = i + length;
      dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD; // 左端を削る
      dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD; // 右端を削る
      dp[i][j] = (dp[i][j] - dp[i + 1][j - 1] + MOD) %
                 MOD; // 両端を削ることで重複を排除

      // ABA -> A
      for (int k = i; k <= j - 2; ++k) {
        if (S[k] == 'A' && S[k + 1] == 'B' && S[k + 2] == 'A') {
          dp[i][j] = (dp[i][j] + dp[i][k] * dp[k + 3][j]) % MOD;
        }
      }

      // BAB -> B
      for (int k = i; k <= j - 2; ++k) {
        if (S[k] == 'B' && S[k + 1] == 'A' && S[k + 2] == 'B') {
          dp[i][j] = (dp[i][j] + dp[i][k] * dp[k + 3][j]) % MOD;
        }
      }
    }
  }

  cout << dp[0][N - 1] << endl;
  return 0;
}
