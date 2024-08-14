#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<vector<int>>> A(
      N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

  for (int x = 1; x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      for (int z = 1; z <= N; ++z) {
        cin >> A[x][y][z];
      }
    }
  }

  // 累積和テーブルを構築
  vector<vector<vector<int>>> prefix_sum(
      N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

  for (int x = 1; x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      for (int z = 1; z <= N; ++z) {
        prefix_sum[x][y][z] =
            A[x][y][z] + prefix_sum[x - 1][y][z] + prefix_sum[x][y - 1][z] +
            prefix_sum[x][y][z - 1] - prefix_sum[x - 1][y - 1][z] -
            prefix_sum[x - 1][y][z - 1] - prefix_sum[x][y - 1][z - 1] +
            prefix_sum[x - 1][y - 1][z - 1];
      }
    }
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

    int sum = prefix_sum[Rx][Ry][Rz] - prefix_sum[Lx - 1][Ry][Rz] -
              prefix_sum[Rx][Ly - 1][Rz] - prefix_sum[Rx][Ry][Lz - 1] +
              prefix_sum[Lx - 1][Ly - 1][Rz] + prefix_sum[Lx - 1][Ry][Lz - 1] +
              prefix_sum[Rx][Ly - 1][Lz - 1] -
              prefix_sum[Lx - 1][Ly - 1][Lz - 1];

    cout << sum << endl;
  }

  return 0;
}
