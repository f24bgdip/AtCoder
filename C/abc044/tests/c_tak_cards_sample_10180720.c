#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n, a, i, j, k;
  int x[3]; // カードの配列

  // 入力を受け取る
  scanf("%d%d", &n, &a);
  for (i = 0; i < n; i++) {
    int X;
    scanf("%d", &X);
    // カードの値から平均値aを減算
    x[i] = X - a;
  }

  // DPテーブル
  long D[2][21];
  memset(D, 0, sizeof(D));

  // 基本ケースの設定
  D[0][10]++;
  // 最初のカードを選ぶ場合
  D[0][10 + x[0]]++;

  // 各カードに対する処理
  for (i = 1; i < n; i++) {
    long *d = D[i & 1] + 10;
    long *e = D[(i + 1) & 1] + 10;

    // 各状態に対する処理
    for (j = -8; j <= 8; j++) {
      // 状態の遷移
      if (j - x[i] < -10 || j - x[i] > 10) {
        printf("Error: Out of bounds access at index %d\n", j - x[i]);
        return -1;
      } else {
        d[j] = e[j] + e[j - x[i]];
      }
    }
  }

  // すべてのカードを選ばない場合を除外
  long ans = D[(n - 1) & 1][10] - 1;

  printf("%ld\n", ans);

  return 0;
}
