#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i <= N - 3; ++i) {
    if (S.compare(i, 3, "ABC") == 0) {
      count++;
    }
  }

  while (Q--) {
    int i;
    char c;
    cin >> i >> c;
    i--;

    for (int j = i - 2; j <= i; ++j) {
      if (j >= 0 && j + 2 < N && S.compare(j, 3, "ABC") == 0) {
        count--;
      }
    }

    S[i] = c;

    for (int j = i - 2; j <= i; ++j) {
      if (j >= 0 && j + 2 < N && S.compare(j, 3, "ABC") == 0) {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
