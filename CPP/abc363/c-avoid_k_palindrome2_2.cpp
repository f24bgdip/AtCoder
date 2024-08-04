#include <algorithm>
#include <iostream>
#include <set>
#include <string>

bool isPalindrome(const std::string &str, int start, int len) {
  int end = start + len - 1;
  for (int i = 0; i < len / 2; ++i) {
    if (str[start + i] != str[end - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string S;
  int N, K;
  std::cin >> N >> K;
  std::cin >> S;

  std::set<std::string> permutations;
  std::sort(S.begin(), S.end());

  do {
    permutations.insert(S);
  } while (std::next_permutation(S.begin(), S.end()));

  int validCount = 0;
  for (const std::string &perm : permutations) {
    bool isValid = true;
    for (int i = 0; i <= N - K; ++i) {
      if (isPalindrome(perm, i, K)) {
        isValid = false;
        break;
      }
    }
    if (isValid) {
      ++validCount;
    }
  }

  std::cout << validCount << std::endl;

  return 0;
}
