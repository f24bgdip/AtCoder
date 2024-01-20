#include <stdio.h>

#define MASK_A (1 << 0)     // ビットマスクで A を表す
#define MASK_B (1 << 1)     // ビットマスクで B を表す
#define MASK_C (1 << 2)     // ビットマスクで C を表す
#define MASK_SPACE (1 << 3) // ビットマスクで空白を表す

void permute(char *perm, int level, int mask, int max_space, int n) {
  if (level == n) {
    perm[level] = '\0';
    printf("%s\n", perm);
    return;
  }

  // A, B, C, 空白の各要素に対してループ
  for (int i = 0; i < 4; i++) {
    int current_mask = 1 << i;
    if (i < 3 && !(mask & current_mask)) { // A, B, C が未使用の場合
      perm[level] = "ABC"[i];
      permute(perm, level + 1, mask | current_mask, max_space, n);
    } else if (i == 3) {                    // 空白文字
      int space_count = (mask >> 3) & 0x07; // 空白文字の数を計算
      if (space_count < max_space) {
        perm[level] = ' ';
        permute(perm, level + 1, mask + MASK_SPACE, max_space, n);
      }
    }
  }
}

int main() {
  int n = 5; // 順列の長さ
  char permutation[n + 1];
  permute(permutation, 0, 0, 2, n); // 空白は最大2つ
  return 0;
}
