#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int N, M, L, Q;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; ++i)
    cin >> B[i];
  cin >> L;
  vector<int> C(L);
  for (int i = 0; i < L; ++i)
    cin >> C[i];
  cin >> Q;
  vector<int> X(Q);
  for (int i = 0; i < Q; ++i)
    cin >> X[i];

  unordered_set<int> sums;
  for (int a : A) {
    for (int b : B) {
      for (int c : C) {
        sums.insert(a + b + c);
      }
    }
  }

  for (int i = 0; i < Q; ++i) {
    if (sums.count(X[i])) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
