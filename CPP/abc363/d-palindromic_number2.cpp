#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::string nthPalindrome(long long n) {
  if (n == 1)
    return "0";

  int digits = 1;
  long long count = 10;
  while (n > count) {
    n -= count;
    digits++;
    if (digits % 2 == 0) {
      count = 9 * static_cast<long long>(std::pow(10, (digits / 2) - 1));
    } else {
      count = 9 * static_cast<long long>(std::pow(10, digits / 2));
    }
  }

  int halfLength = (digits + 1) / 2;
  long long halfBase = 1;
  for (int i = 1; i < halfLength; ++i) {
    halfBase *= 10;
  }
  long long halfNumber = halfBase + n - 1;

  std::string halfStr = std::to_string(halfNumber);
  std::string palindromeStr = halfStr;

  if (digits % 2 == 1) {
    palindromeStr.pop_back();
  }

  std::reverse(halfStr.begin(), halfStr.end());
  palindromeStr += halfStr;

  return palindromeStr;
}

int main() {
  long long N;
  std::cin >> N;
  std::cout << nthPalindrome(N) << std::endl;
  return 0;
}
