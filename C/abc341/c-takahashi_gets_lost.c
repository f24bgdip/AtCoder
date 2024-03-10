#include <stdio.h>

int main() {
  int H, W, N;
  if (scanf("%d %d %d", &H, &W, &N) != 3)
    return -1;

  char T[N];
  if (scanf("%s", T) != 1)
    return -1;

  char S[H][W + 1];
  for (int i = 0; i < H; i++) {
    if (scanf("%s", S[i]) != 1)
      return -1;
  }

  // Playerの探索エリア
  char explore[H - 2][W - 1];
  for (int i = 0; i < sizeof(moves) - 1; i++) {
    switch (moves[i]) {
    case 'U':
      row--;
      break;
    case 'D':
      row++;
      break;
    case 'L':
      col--;
      break;
    case 'R':
      col++;
      break;
    }
    grid[row][col] = 'M'; // 移動先のマスを 'M' に変更
  }

  int row, col;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        row = i;
        col = j;
        break;
      }
    }
  }

  int count = 0;

  // 手順に従って移動
  for (int i = 0; i < N; i++) {
    if (T[i] == 'L' && col > 0 && S[row][col - 1] != '#') {
      col--;
      if (S[row][col] != '#')
        count++;
    } else if (T[i] == 'R' && col < W - 1 && S[row][col + 1] != '#') {
      col++;
      if (S[row][col] != '#')
        count++;
    } else if (T[i] == 'U' && row > 0 && S[row - 1][col] != '#') {
      row--;
      if (S[row][col] != '#')
        count++;
    } else if (T[i] == 'D' && row < H - 1 && S[row + 1][col] != '#') {
      row++;
      if (S[row][col] != '#')
        count++;
    }
  }

  printf("%d\n", count);

  return 0;
}
  