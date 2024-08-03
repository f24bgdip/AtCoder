#include <iostream>
#include <vector>

int main() {
  int N, K, X;
  std::cin >> N >> K >> X;

  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  for (int i = 0; i <= K - 1; ++i) {
    std::cout << A[i] << " ";
  }

  std::cout << X << " ";

  for (int i = K; i < N; ++i) {
    std::cout << A[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}
