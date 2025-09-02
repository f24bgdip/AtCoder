#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  vector<string> X;
  vector<int> diffs(S.size(), 0);

  for (int i = 0; i < S.size(); ++i) {
    diffs[i] = S[i] - T[i];
  }

  while (S != T) {
    bool found = false;

    for (int i = 0; i < S.size(); ++i) {
      if (diffs[i] > 0) {
        // cout << "Changing S[" << i << "] from '" << S[i] << "' to '" << T[i]
        // << "'." << endl;
        S[i] = T[i];
        X.push_back(S);
        diffs[i] = 0;
        // cout << "Updated S: " << S << endl;
        found = true;
        break;
      }
    }

    if (!found) {
      for (int i = S.size() - 1; i >= 0; --i) {
        if (diffs[i] < 0) {
          // cout << "Changing S[" << i << "] from '" << S[i] << "' to '" <<
          // T[i] << "'." << endl;
          S[i] = T[i];
          X.push_back(S);
          diffs[i] = 0;
          // cout << "Updated S: " << S << endl;
          break;
        }
      }
    }
  }

  cout << X.size() << endl;
  for (const string &str : X) {
    cout << str << endl;
  }

  return 0;
}
