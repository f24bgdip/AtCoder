#include <iostream>
#include <string>
#include <vector>

using namespace std;

string constructString(const string &S, const string &T, const string &X) {
  string result;
  for (char c : X) {
    if (c == '0') {
      result += S;
    } else {
      result += T;
    }
  }
  return result;
}

bool isValidT(const string &S, const string &X, const string &Y, string &T) {
  size_t lenS = S.length();
  size_t lenX = X.length();
  size_t lenY = Y.length();

  // 長さが異なる場合は不可能
  if (lenX != lenY) {
    return false;
  }

  // f(S,T,X) と f(S,T,Y) のフレーズを構築
  string f_X = constructString(S, "T", X);
  string f_Y = constructString(S, "T", Y);

  // フレーズの数が異なる場合に少ない方を多い方に合わせる
  vector<string> phrases_X, phrases_Y;
  size_t startX = 0, startY = 0;
  for (size_t i = 0; i < lenX; ++i) {
    if (X[i] == '0') {
      phrases_X.push_back(S);
      startX += lenS;
    } else {
      phrases_X.push_back(f_X.substr(startX, lenS));
      startX += lenS;
    }

    if (Y[i] == '0') {
      phrases_Y.push_back(S);
      startY += lenS;
    } else {
      phrases_Y.push_back(f_Y.substr(startY, lenS));
      startY += lenS;
    }
  }

  // フレーズの一致確認
  size_t n = phrases_X.size();
  size_t m = phrases_Y.size();
  if (n != m) {
    return false;
  }

  for (size_t i = 0; i < n; ++i) {
    if (phrases_X[i] != phrases_Y[i]) {
      return false;
    }
  }

  // 一貫した T を見つける
  T = "";
  for (size_t i = 0; i < n; ++i) {
    if (X[i] == '1' && Y[i] == '1') {
      if (T.empty()) {
        T = phrases_X[i];
      } else if (T != phrases_X[i]) {
        return false;
      }
    }
  }

  // 再度 f(S,T,X) と f(S,T,Y) を構築して確認
  f_X = constructString(S, T, X);
  f_Y = constructString(S, T, Y);

  return f_X == f_Y;
}

int main() {
  string S = "araara";
  string X = "01";
  string Y = "111";
  string T;

  if (isValidT(S, X, Y, T)) {
    cout << "Yes" << endl;
    cout << "T: " << T << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
