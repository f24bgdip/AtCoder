#include <stdio.h>
#include <stdlib.h>

void fill(int N, int grid[N][N]) {
  int x = N / 2, y = N / 2;  // 中央の座標
  int dx = 0, dy = -1;       // 初期方向
  int steps = 1, change = 0; // ステップ数と方向変更のカウント
  int part = N * N;          // パーツ番号の最大値から開始

  for (int i = 0; i < N * N; ++i) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
      grid[y][x] = part--;
      // printf("OK: Part %d placed at (%d, %d)\n", part + 1, x, y);
    } else {
      // printf("NG: Part %d placed at (%d, %d)\n", part + 1, x, y);
    }

    // ステップ数を進んだら、方向を変更
    if (--steps == 0) {
      steps = change / 2 + 1; // ステップ数の更新
      change++;
      // 方向を90度回転
      int temp = dx;
      dx = -dy;
      dy = temp;
      // printf("Direction changed: dx=%d, dy=%d, steps=%d\n", dx, dy, steps);
    }

    // 次の位置へ移動
    x += dx;
    y += dy;
  }
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int grid[N][N];

  fill(N, grid);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == N / 2 && j == N / 2)
        printf("T ");
      else
        printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
