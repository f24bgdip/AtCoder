#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s, int i, int k) {
  for (int j = 1; j <= k; ++j) {
    if (s[i + j] != s[i + k + 1 - j]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s;
  int n, k;
  cin >> n >> k;
  cin >> s;

  int count = 0;
  sort(s.begin(), s.end());
  do {
    bool ok = true;
    for (int i = 0; i <= n - k; ++i) {
      if (is_palindrome(s, i, k)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++count;
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << count << endl;

  return 0;
}
