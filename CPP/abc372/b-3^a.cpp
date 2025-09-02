#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<long long> values(11);

void precompute() {
  for (int i = 0; i <= 10; i++) {
    values[i] = pow(3, i);
  }
}

bool find(int index, int N, int M, vector<int> &A, long long s,
          unordered_set<long long> &visited) {
  if (s > M || visited.find(s) != visited.end()) {
    return false;
  }

  if (index == N) {
    return s == M;
  }

  visited.insert(s);

  for (int i = 10; i >= 0; i--) {
    A[index] = i;
    if (find(index + 1, N, M, A, s + values[i], visited)) {
      return true;
    }
  }
  return false;
}

int main() {
  int M;
  cin >> M;

  precompute();

  for (int N = 1; N <= 20; N++) {
    vector<int> A(N, 0);
    unordered_set<long long> visited;
    if (find(0, N, M, A, 0, visited)) {
      cout << N << endl;
      for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
      }
      cout << endl;
      break;
    }
  }

  return 0;
}
