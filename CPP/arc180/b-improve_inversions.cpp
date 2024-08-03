#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  vector<pair<int, int>> operations;

  // このループで条件に合うペアを探して、操作を行う
  for (int l = 0; l < N - 1; ++l) {
    for (int r = l + 1; r < N; ++r) {
      if (r - l >= K && P[l] > P[r]) {
        operations.push_back({l + 1, r + 1});
        swap(P[l], P[r]);
      }
    }
  }

  cout << operations.size() << endl;
  for (auto op : operations) {
    cout << op.first << " " << op.second << endl;
  }

  return 0;
}
