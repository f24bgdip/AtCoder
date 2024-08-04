#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::string nthPalindrome(long long n) {
  if (n == 1)
    return "0";
  n--;

  int digits = 1;
  long long count = 9;
  while (n >= count) {
    n -= count;
    digits++;
    count = 9 * static_cast<long long>(std::pow(10, (digits - 1) / 2));
  }

  int halfLength = (digits + 1) / 2;
  long long halfNumber = static_cast<long long>(std::pow(10, halfLength - 1)) + n;

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
