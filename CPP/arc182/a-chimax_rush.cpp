#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 998244353;

int N, Q;
vector<int> P, V;

void printS(const vector<int> &S) {
  for (int i = 0; i < N; ++i) {
    cout << S[i];
  }
  cout << endl;
}

bool Operation(vector<int> &S, int start, int end, int value) {
  for (int j = start; j <= end; ++j) {
    if (S[j] > value) {
      return false;
    } else {
      S[j] = value;
    }
  }
  return true;
}

int dp(int i, vector<int> S) {
//  cout << "dp開始: i = " << i << ", S = ";
 // printS(S);

  if (i == Q)
    return 1;

  int count = 0;

  // 操作A
  vector<int> newS = S;
  if (Operation(newS, 0, P[i] - 1, V[i])) {
    int next_count = dp(i + 1, newS);
    count = (count + next_count) % MOD;
//    cout << "A操作: i = " << i << ", S = ";
//    printS(newS);
//    cout << "部分結果 = " << next_count << ", 合計 = " << count << endl;
  }

  // B操作
  newS = S;
  if (Operation(newS, P[i] - 1, N - 1, V[i])) {
    int next_count = dp(i + 1, newS);
    count = (count + next_count) % MOD;
    // デバッグ情報を出力
//    cout << "B操作: i = " << i << ", S = ";
//    printS(newS);
//    cout << "部分結果 = " << next_count << ", 合計 = " << count << endl;
  }

  return count;
}

int main() {
  cin >> N >> Q;
  P.resize(Q);
  V.resize(Q);

  for (int i = 0; i < Q; ++i) {
    cin >> P[i] >> V[i];
  }

  vector<int> S(N, 0);
  int result = dp(0, S);

  cout << result << endl;

  return 0;
}
