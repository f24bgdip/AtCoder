#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<vector<int>>> sum(
      N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

  for (int x = 1; x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      for (int z = 1; z <= N; ++z) {
        int value;
        cin >> value;
        sum[x][y][z] = value + sum[x - 1][y][z] + sum[x][y - 1][z] +
                       sum[x][y][z - 1] - sum[x - 1][y - 1][z] -
                       sum[x - 1][y][z - 1] - sum[x][y - 1][z - 1] +
                       sum[x - 1][y - 1][z - 1];
      }
    }
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

    int result = sum[Rx][Ry][Rz] - sum[Lx - 1][Ry][Rz] - sum[Rx][Ly - 1][Rz] -
                 sum[Rx][Ry][Lz - 1] + sum[Lx - 1][Ly - 1][Rz] +
                 sum[Lx - 1][Ry][Lz - 1] + sum[Rx][Ly - 1][Lz - 1] -
                 sum[Lx - 1][Ly - 1][Lz - 1];

    cout << result << endl;
  }

  return 0;
}
