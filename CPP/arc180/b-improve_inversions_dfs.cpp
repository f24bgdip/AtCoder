#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, K;
vector<int> P;
vector<pair<int, int>> best_operations;
vector<pair<int, int>> current_operations;

void dfs() {
  bool found = false;
  for (int l = 0; l < N - 1; ++l) {
    for (int r = l + 1; r < N; ++r) {
      if (r - l >= K && P[l] > P[r]) {
        found = true;
        current_operations.push_back({l + 1, r + 1});
        swap(P[l], P[r]);
        dfs();
        swap(P[l], P[r]);
        current_operations.pop_back();
      }
    }
  }
  if (!found) {
    if (current_operations.size() > best_operations.size()) {
      best_operations = current_operations;
    }
  }
}

int main() {
  cin >> N >> K;
  P.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  dfs();

  cout << best_operations.size() << endl;
  for (auto &op : best_operations) {
    cout << op.first << " " << op.second << endl;
  }

  return 0;
}
