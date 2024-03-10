#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string T;
  int N;
  cin >> T >> N;

  vector<vector<int>> dp(T.size() + 1, vector<int>(T.size() + 1, INT_MAX));
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;

    vector<string> S(A);
    for (int j = 0; j < A; j++) {
      cin >> S[j];
    }

    for (int j = 0; j <= T.size(); j++) {
      for (int k = 0; k <= j; k++) {
        for (const string &s : S) {
          if (k + s.size() <= j && dp[i - 1][j - k - s.size()] != INT_MAX) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - k - s.size()] + 1);
          }
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i <= T.size(); i++) {
    ans = min(ans, dp[N][i]);
  }

  if (ans == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
