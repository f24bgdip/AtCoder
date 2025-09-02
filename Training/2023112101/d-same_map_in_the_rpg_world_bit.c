#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

void shift_horizontal(unsigned int grid[MAX_SIZE], int H, int W) {
  for (int i = 0; i < H; i++) {
    unsigned int right_shifted = grid[i] >> 1;
    unsigned int wrap_around = (grid[i] & 1) << (W - 1);
    grid[i] = right_shifted | wrap_around;
  }
}

bool check_grids_equal(unsigned int A[MAX_SIZE], unsigned int B[MAX_SIZE],
                       int H, int v) {
  for (int i = 0; i < H; i++) {
    if (A[(i + v) % H] != B[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int H, W;
  if (scanf("%d %d", &H, &W) != 2)
    return -1;

  unsigned int A[MAX_SIZE] = {0}, B[MAX_SIZE] = {0};
  int a_cnt[MAX_SIZE] = {0}, b_cnt[MAX_SIZE] = {0};
  int total_a_cnt = 0, total_b_cnt = 0;
  char line[MAX_SIZE + 1];

  for (int i = 0; i < H; i++) {
    if (scanf("%s", line) != 1)
      return -1;
    for (int j = 0; j < W; j++) {
      if (line[j] == '#') {
        A[i] |= 1 << (W - j - 1);
        a_cnt[i]++;
      }
    }
    total_a_cnt += a_cnt[i];
  }

  for (int i = 0; i < H; i++) {
    if (scanf("%s", line) != 1)
      return -1;
    for (int j = 0; j < W; j++) {
      if (line[j] == '#') {
        B[i] |= 1 << (W - j - 1);
        b_cnt[i]++;
      }
    }
    total_b_cnt += b_cnt[i];
  }

  if (total_a_cnt != total_b_cnt) {
    printf("No\n");
    return 0;
  }

  // shift vertical
  for (int v = 0; v < H; v++) {
    // check vertical
    bool v_match = true;
    for (int i = 0; i < H; i++) {
      v_match &= (b_cnt[i] == a_cnt[(i + v) % H]);
    }
    if (v_match) {
      // shift horizontal
      for (int h = 0; h < W; h++) {
        if (check_grids_equal(A, B, H, v)) {
          printf("Yes\n");
          return 0;
        } else {
          shift_horizontal(A, H, W);
        }
      }
    }
  }
  printf("No\n");
  return 0;
}
