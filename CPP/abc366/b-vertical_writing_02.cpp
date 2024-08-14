#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> input(N);
  cin.ignore();
  int max_length = 0;

  // 各文字列を入力し、最大の長さを記録
  for (int i = 0; i < N; ++i) {
    getline(cin, input[i]);
    max_length = max(max_length, static_cast<int>(input[i].length()));
  }

  // すべての文字列の長さを最大の長さに揃える
  for (int i = 0; i < N; ++i) {
    if (input[i].length() < max_length) {
      input[i].append(max_length - input[i].length(), '*');
    }
  }

  // 縦方向に文字を配置するための二次元配列を使用
  vector<string> output(max_length, string(N, '*'));

  for (int i = 0; i < max_length; ++i) {
    for (int j = 0; j < N; ++j) {
      output[i][N - j - 1] = input[j][i];
    }
  }

  // 無駄な '*' を取り除く
  for (auto &line : output) {
    while (!line.empty() && line.back() == '*') {
      line.pop_back();
    }
  }

  // 結果を出力
  for (const auto &line : output) {
    cout << line << endl;
  }

  return 0;
}
