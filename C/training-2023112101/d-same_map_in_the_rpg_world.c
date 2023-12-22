#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

void shift_vertical(char grid[MAX_SIZE][MAX_SIZE], int H, int W) {
  char temp[MAX_SIZE];
  for (int j = 0; j < W; j++) {
    temp[j] = grid[H - 1][j];
  }

  for (int i = H - 1; i > 0; i--) {
    for (int j = 0; j < W; j++) {
      grid[i][j] = grid[i - 1][j];
    }
  }

  for (int j = 0; j < W; j++) {
    grid[0][j] = temp[j];
  }
}

void shift_horizontal(char grid[MAX_SIZE][MAX_SIZE], int H, int W) {
  char temp;
  for (int i = 0; i < H; i++) {
    temp = grid[i][W - 1];
    for (int j = W - 1; j > 0; j--) {
      grid[i][j] = grid[i][j - 1];
    }
    grid[i][0] = temp;
  }
}

bool check_grids_equal(char A[MAX_SIZE][MAX_SIZE], char B[MAX_SIZE][MAX_SIZE],
                       int H, int W) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A[i][j] != B[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int H, W;
  scanf("%d %d", &H, &W);

  char A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < H; i++) {
    if (scanf("%s", A[i]) != 1)
      return -1;
  }

  for (int i = 0; i < H; i++) {
    if (scanf("%s", B[i]) != 1)
      return -1;
  }

  for (int v = 0; v < H; v++) {
    for (int h = 0; h < W; h++) {
      if (check_grids_equal(A, B, H, W)) {
        printf("Yes\n");
        return 0;
      }
      shift_horizontal(A, H, W);
    }
    shift_vertical(A, H, W);
  }

  printf("No\n");

  return 0;
}
