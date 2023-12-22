#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  int max_count = 0;
  int j = 0;
  for (int i = 0; i < N; i++) {
    while (j < N && A[j] - A[i] < M) {
      j++;
    }
    if (j - i > max_count) {
      max_count = j - i;
    }
  }

  std::cout << max_count << std::endl;
  return 0;
}
