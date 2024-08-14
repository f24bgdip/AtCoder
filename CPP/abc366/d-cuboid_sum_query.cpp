#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N * N * N);
  for (int i = 0; i < N * N * N; ++i) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

    int sum = 0;
    for (int x = Lx; x <= Rx; ++x) {
      for (int y = Ly; y <= Ry; ++y) {
        for (int z = Lz; z <= Rz; ++z) {
          sum += A[(x - 1) * N * N + (y - 1) * N + (z - 1)];
        }
      }
    }

    cout << sum << endl;
  }

  return 0;
}
