#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int> &A, int K) {
  int N = A.size();
  if (N == K) {
    return 0;
  }

  sort(A.begin(), A.end());

  int min_diff = INT_MAX;
  int rm = N - K;

  for (int i = 0; i <= K; ++i) {
    int current_diff = A[i + rm - 1] - A[i];
    min_diff = min(min_diff, current_diff);
  }

  return min_diff;
}

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int result = calc(A, K);
  cout << result << endl;

  return 0;
}
