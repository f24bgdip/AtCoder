#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int operation(vector<int> &p) {
  int N = p.size();
  vector<int> sorted_p(p);
  sort(sorted_p.begin(), sorted_p.end());

  // 既にソートされている場合
  if (p == sorted_p) {
    return 0;
  }

  // 操作1回目
  int best_k = -1;
  vector<int> best_p;
  for (int k = 2; k <= N; ++k) {
    vector<int> temp_p = p;
    sort(temp_p.begin(), temp_p.begin() + k - 1);
    if (temp_p < p) {
      best_k = k;
      best_p = temp_p;
    }
  }

  // 操作回数2回目以降
  int operations = 1;
  p = best_p;
  while (p != sorted_p) {
    for (int k = 1; k < N; ++k) {
      vector<int> temp_p = p;
      sort(temp_p.begin() + k, temp_p.end());
      if (temp_p == sorted_p) {
        p = temp_p;
        operations++;
        break;
      }
    }
  }

  return operations;
}

int main() {
  int T;
  cin >> T;

  for (int j = 0; j < T; ++j) {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
      cin >> p[i];
    }
    cout << operation(p) << endl;
  }

  return 0;
}
