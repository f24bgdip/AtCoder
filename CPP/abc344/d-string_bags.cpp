#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string T;
  cin >> T;

  int N;
  cin >> N;

  unordered_map<char, vector<string>> bags;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    for (int j = 0; j < A; ++j) {
      string str;
      cin >> str;
      bags[str[0]].push_back(str);
    }
  }

  int cost = 0;
  string S;
  for (char c : T) {
    // デバッグ出力: 現在の文字を表示
    cout << "Processing character: " << c << endl;

    // 文字が存在しない場合や袋が空の場合は-1を出力して終了
    if (bags.find(c) == bags.end() || bags[c].empty()) {
      cout << "-1" << endl;
      return 0;
    }
    bool found = false;
    // 袋から選択する際に、Sの末尾と同じ文字で始まるものを選択する
    for (int i = 0; i < bags[c].size(); ++i) {
      if (bags[c][i][0] == S.back()) {
        string str = bags[c][i];
        bags[c].erase(bags[c].begin() + i);
        ++cost;
        S += str;
        // デバッグ出力: 選択された文字列を表示
        cout << "Selected string from bag: " << str << endl;
        found = true;
        break;
      }
    }
    // 選択された文字列がない場合は-1を出力して終了
    if (!found) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << "Final cost: " << cost << endl;

  return 0;
}
