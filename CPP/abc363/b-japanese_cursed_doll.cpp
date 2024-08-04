#include <iostream>
#include <vector>

int main() {
  int N, T, P;
  std::cin >> N >> T >> P;

  std::vector<int> L(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> L[i];
  }

  int loopCount = 0;
  while (true) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
      int l = L[i] + loopCount;
      if (l >= T) {
        ++count;
      }
    }
    if (count >= P) {
      break;
    }
    ++loopCount;
  }

  std::cout << loopCount << std::endl;

  return 0;
}
