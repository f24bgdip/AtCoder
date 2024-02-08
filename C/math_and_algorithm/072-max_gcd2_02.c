// This code is based on #46365280

#include <stdio.h>

int main() {
  int A, B;
  if (scanf("%d %d", &A, &B) != 2)
    return -1;

  int x = B - A;
  while (1) {
    // 範囲内でxで割り切れる数が2つ以上存在するかをチェック
    if (B / x - (A - 1) / x >= 2) {
      // 条件を満たす最大のxが見つかった
      break;
    }
    --x;
  }
  printf("%d\n", x);

  return 0;
}
