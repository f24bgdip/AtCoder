#include <stdio.h>

int main() {
  int H, W, N;
  if (scanf("%d %d %d", &H, &W, &N) != 3)
    return -1;

  char grid[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      grid[i][j] = '.';
    }
  }

  int x = 0, y = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  int dir = 0;

  for (int step = 0; step < N; step++) {
    if (grid[y][x] == '.') {
      // 白の場合
      // 黒に塗り替え
      grid[y][x] = '#';
      // 時計回りに90度回転
      dir = (dir + 1) % 4;
    } else {
      // 黒の場合
      // 白に塗り替え
      // 反時計回りに90度回転
      grid[y][x] = '.';
      dir = (dir + 3) % 4;
    }

    // 位置の更新
    x = (x + dx[dir] + W) % W;
    y = (y + dy[dir] + H) % H;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
