#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 条件を満たす木の数を計算する関数
vector<int> countVisiblePairs(const vector<int> &heights) {
  int n = heights.size();
  vector<int> result(n, 0);
  stack<int> s;

  // 右から左へ走査
  for (int i = n - 1; i >= 0; --i) {
    // デバッグ出力：現在の木の情報
    cout << "現在の木のインデックス: " << i + 1 << " 高さ: " << heights[i]
         << endl;

    // スタックのトップが現在の木の高さよりも低ければ、条件を満たす
    while (!s.empty() && s.top() <= heights[i]) {
      cout << "  スタックから " << s.top() << " をポップ: 現在の木よりも低い"
           << endl;
      s.pop();
    }

    // 現在の木から見える木の数はスタックの要素数
    result[i] = s.size();
    cout << "  見える木の数 (スタックの要素数): " << result[i] << endl;

    // 現在の木をスタックに追加
    s.push(heights[i]);
    cout << "  スタックに " << heights[i] << " をプッシュ" << endl;
  }

  return result;
}

int main() {
  int n;
  cout << "木の数を入力してください: ";
  cin >> n;
  vector<int> heights(n);
  cout << "各木の高さを入力してください: ";
  for (int i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  vector<int> result = countVisiblePairs(heights);

  cout << "条件を満たすペアの数: ";
  for (int i = 0; i < n; ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
