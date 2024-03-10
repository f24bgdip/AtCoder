#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  int num;

  while (std::cin >> num && num != 0) {
    numbers.push_back(num);
  }

  numbers.push_back(0);

  for (int i = numbers.size() - 1; i >= 0; --i) {
    std::cout << numbers[i] << std::endl;
  }

  return 0;
}
