#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<std::string> input(N);
  std::cin.ignore();
  int max_length = 0;

  for (int i = 0; i < N; ++i) {
    std::getline(std::cin, input[i]);

    if (input[i].length() < max_length) {
      input[i].append(max_length - input[i].length(), '*');
    }
    max_length = std::max(max_length, static_cast<int>(input[i].length()));
  }

  for (int i = 0; i < max_length; ++i) {
    for (int j = N - 1; j >= 0; --j) {
      std::cout << input[j][i];
    }
    std::cout << std::endl;
  }

  return 0;
}
