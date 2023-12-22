#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
  int grid[MAX_SIZE][MAX_SIZE];
  int H, W;
} Grid;

void read_grid(Grid *g) {
  for (int i = 0; i < g->H; i++) {
    for (int j = 0; j < g->W; j++) {
      scanf("%d", &g->grid[i][j]);
    }
  }
}

bool find_element(const Grid *A, const Grid *B) {
  for (int i = 0; i < A->H; i++) {
    for (int j = 0; j < A->W; j++) {
      int element = A->grid[i][j];
      bool rowMatch[MAX_SIZE] = {false}, colMatch[MAX_SIZE] = {false};
      bool found = false;

      // グリッドBで要素が見つかるすべての位置をチェック
      for (int x = 0; x < B->H; x++) {
        for (int y = 0; y < B->W; y++) {
          if (B->grid[x][y] == element) {
            rowMatch[x] = true; // 行のマッチを記録
            colMatch[y] = true; // 列のマッチを記録
            printf("Element %d: A(%d,%d) -> B(%d,%d)\n", element, i, j, x, y);
            found = true;
          }
        }
      }

      // 要素が見つからない場合、グリッドAとBは一致しない
      if (!found)
        return false;

      // 要素が複数の行または列にまたがっているかチェック
      int rowCount = 0, colCount = 0;
      for (int x = 0; x < B->H; x++)
        if (rowMatch[x])
          rowCount++;
      for (int y = 0; y < B->W; y++)
        if (colMatch[y])
          colCount++;
      if (rowCount > 1 && colCount > 1)
        return false; // 行と列の両方で複数マッチする場合、一致しない
    }
  }
  return true; // すべての要素が一致する場合
}

int main() {
  Grid A, B;
  if (scanf("%d %d", &A.H, &A.W) != 2)
    return -1;
  B.H = A.H;
  B.W = A.W;

  read_grid(&A);
  read_grid(&B);

  bool match = find_element(&A, &B);
  printf("%s\n", match ? "Yes" : "No");

  return 0;
}
