#include <iostream>

int main() {
  int r;
  std::cin >> r;

  int currentLevel = r / 100;
  int nextLevel = currentLevel + 1;

  int nextThreshold = nextLevel * 100;
  int addition = nextThreshold - r;
  std::cout << addition << std::endl;

  return 0;
}
