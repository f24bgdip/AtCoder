#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  vector<pair<int, int>> points(N);
  for (int i = 0; i < N; i++) {
    cin >> points[i].first >> points[i].second;
  }

  int count = 0;
  for (int x = -D; x <= D; x++) {
    for (int y = -D; y <= D; y++) {
      int total_distance = 0;

      for (int i = 0; i < N; i++) {
        total_distance += abs(x - points[i].first) + abs(y - points[i].second);
      }

      if (total_distance <= D) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
