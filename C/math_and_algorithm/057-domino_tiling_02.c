#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_STATES 8

// K=3のグリッドにおいて、状態を表すビットマスクを計算する関数
int calculateState(int row1, int row2, int row3) {
  // 各行におけるドミノの配置をビットで表現し、それらを組み合わせて状態を表す整数を返す
  return (row1 << 2) | (row2 << 1) | row3;
}

// 特定の状態から遷移可能な状態を返す関数
int getNextStates(int currentState) {
  // currentStateに基づいて、次の列に遷移可能な状態のリストを計算して返す
  // （実際の実装では、ここに遷移ロジックが必要になります）
}

// K=3のグリッドにドミノを敷き詰める方法の数を計算する関数
long long countDominoTilings(int N) {
  // dp[i][state]は、i列目で特定の状態が存在する敷き詰め方の数
  long long dp[N + 1][8]; // 3行の状態は2^3=8通りあるため、8とする
  memset(dp, 0, sizeof(dp));

  // 基底ケースの初期化
  dp[0][0] = 1; // グリッドの開始時点では、まだ何も置かれていない状態

  // DPテーブルを埋める
  for (int i = 1; i <= N; i++) {
    for (int state = 0; state < 8; state++) {
      int nextStates = getNextStates(state);
      // 次の状態に遷移するロジックをここに実装する
      // dp[i][nextState] += dp[i-1][state];
    }
  }

  // 最終列のすべての状態の合計が答え
  long long totalWays = 0;
  for (int state = 0; state < 8; state++) {
    totalWays = (totalWays + dp[N][state]) % MOD;
  }

  return totalWays;
}

int main() {
  int K, N;
  if (scanf("%d %d", &K, &N) != 2)
    return -1;

  printf("3x%dグリッドにドミノを敷き詰める方法の数: %lld\n", N,
         countDominoTilings(N));
  return 0;
}



// ここに状態遷移のロジックを実装する
void computeTransitions(int transitions[][MAX_STATES]) {
    // transitions[state][nextState] = 1 は、状態 state から nextState への遷移が可能であることを意味する
}

// 3xNグリッドにドミノを敷き詰める方法の数を計算する関数
long long countDominoTilings(int N) {
    long long dp[N + 1][MAX_STATES];
    int transitions[MAX_STATES][MAX_STATES];
    
    // 状態遷移表を計算する
    computeTransitions(transitions);
    
    // DPテーブルを初期化する
    for (int i = 0; i <= N; ++i) {
        for (int state = 0; state < MAX_STATES; ++state) {
            dp[i][state] = 0;
        }
    }
    dp[0][0] = 1;  // 基底ケース

    // DPテーブルを埋める
    for (int i = 1; i <= N; ++i) {
        for (int state = 0; state < MAX_STATES; ++state) {
            for (int nextState = 0; nextState < MAX_STATES; ++nextState
