#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 60
#define INF 1000000000

int N;
char grid[MAX_N][MAX_N + 1];
int dp[MAX_N][MAX_N][MAX_N][MAX_N];

// 移動方向（上、右、下、左）
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// DPで使用する関数のプロトタイプ宣言
int minMoves(int x1, int y1, int x2, int y2);

// プレイヤーが移動可能かチェック
int isValid(int x, int y) {
  printf("Checking isValid for x=%d, y=%d, N=%d\n", x, y, N);
  return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != '#';
}

// 2人のプレイヤーを同じマスに集めるための最小操作回数を計算
int minMoves(int x1, int y1, int x2, int y2) {
  // すでに同じマスにいる
  if (x1 == x2 && y1 == y2)
    return 0;
  // 既に計算済み
  if (dp[x1][y1][x2][y2] != -1)
    return dp[x1][y1][x2][y2];

  int result = INF;
  // 4方向に対して試行
  for (int dir = 0; dir < 4; dir++) {
    int nx1 = x1 + dx[dir], ny1 = y1 + dy[dir];
    int nx2 = x2 + dx[dir], ny2 = y2 + dy[dir];
    // プレイヤー1が移動不可
    if (!isValid(nx1, ny1)) {
      nx1 = x1;
      ny1 = y1;
    }
    // プレイヤー2が移動不可
    if (!isValid(nx2, ny2)) {
      nx2 = x2;
      ny2 = y2;
    }
    int moves = minMoves(nx1, ny1, nx2, ny2);
    if (moves != INF)
      result = result < 1 + moves ? result : 1 + moves;
  }

  return dp[x1][y1][x2][y2] = result;
}

int main() {
  if (scanf("%d", &N) != 1)
    return -1;

  int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  for (int i = 0; i < N; i++) {
    if (scanf("%s", grid[i]) != 1)
      return -1;

    // プレイヤーの位置を探索
    // 0ベース
    for (int j = 0; j < N; j++)
      if (grid[i][j] == 'P') {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        } else {
          x2 = i;
          y2 = j;
        }
      }
  }

  // DPテーブルの初期化
  memset(dp, -1, sizeof(dp));

  int result = minMoves(x1, y1, x2, y2);
  if (result == INF)
    printf("-1\n");
  else
    printf("%d\n", result);

  return 0;
}
