#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int H, W;
  if (scanf("%d %d", &H, &W) != 2)
    return -1;

  int A[H][W];
  int row_sums[H], col_sums[W];
  for (int j = 0; j < W; j++)
    col_sums[j] = 0;

  for (int i = 0; i < H; i++) {
    row_sums[i] = 0;
    for (int j = 0; j < W; j++) {
      if (scanf("%d", &A[i][j]) != 1)
        return -1;
      row_sums[i] += A[i][j];
      col_sums[j] += A[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int sum = row_sums[i] + col_sums[j] - A[i][j];
      printf("%d ", sum);
    }
    printf("\n");
  }

  return 0;
}
