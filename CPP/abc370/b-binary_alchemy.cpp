#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> A[i][j];
    }
  }

  int i = 0;

  for (int j = 0; j < N; j++) {
    if (i >= j) {
      i = A[i][j];
      i--;
    } else {
      i = A[j][i];
      i--;
    }
  }

  cout << i + 1 << endl;

  return 0;
}
