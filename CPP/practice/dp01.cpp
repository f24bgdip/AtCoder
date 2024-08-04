#include <iostream>

int fibonacci_iterative(int x) {
  if (x <= 1) {
    return x;
  }

  int n[x];
  n[0] = 0, n[1] = 1;
  for (int i = 2; i <= x; ++i) {
    n[i] = n[i - 1] + n[i - 2];
  }

  return n[x];
}

int main() {
  int n;
  std::cout << "フィボナッチ数列の項数を入力してください: ";
  std::cin >> n;
  std::cout << "フィボナッチ数列の " << n << " 番目の項は "
            << fibonacci_iterative(n) << " です。" << std::endl;
  return 0;
}
