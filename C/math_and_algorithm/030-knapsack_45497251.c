#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
  int N, W;
  scanf("%d %d", &N, &W);

  long v[101], w[101];
  for (int i = 0; i < N; i++) {
    scanf("%ld %ld", &w[i], &v[i]);
  }

  // 1次元DPテーブル
  long score[100002] = {};
  // 全てのアイテムについて繰り返す
  for (int i = 0; i < N; i++) {
    // 重さの制限Wまで逆方向に繰り返す
    // これにより、同じアイテムを重複して加算することを防ぐ
    for (int j = W; j >= 0; j--) {
      // 現在のアイテムを加えた重さが制限を超えない場合にのみ処理
      if (j + w[i] <= W)
        // score[j + w[i]]を更新する
        // これは、現在のアイテムを追加することによって達成可能な新しい価値と、
        // 既に計算されている同じ重さでの最大価値とを比較し、
        // より大きい方を選択する
        score[j + w[i]] = MAX(score[j] + v[i], score[j + w[i]]);
    }
  }

  printf("%ld\n", score[w]);
  return 0;
}
