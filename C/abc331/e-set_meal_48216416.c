#include <stdio.h>
#include <stdlib.h>

// 2次元配列を比較する関数
int cmp_int_2d(const void *a, const void *b) {
  int *a_ = (int *)a;
  int *b_ = (int *)b;

  // 主菜または副菜のインデックスを比較
  if (a_[0] < b_[0])
    return -1;
  if (a_[0] > b_[0])
    return 1;
  if (a_[1] < b_[1])
    return -1;
  if (a_[1] > b_[1])
    return 1;
  return 0;
}

int main() {
  int n, m, l;
  // 入力
  scanf("%d %d %d", &n, &m, &l);

  int a[n];     // 主菜の価格
  int b[m][2];  // 副菜の価格とインデックス
  int cd[l][2]; // 禁止された組み合わせのインデックス
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", b[i]);
    // 副菜のインデックス
    b[i][1] = i;
  }
  for (int i = 0; i < l; i++) {
    scanf("%d %d", cd[i], cd[i] + 1);
    // インデックスを0ベースに変更
    cd[i][0]--;
    cd[i][1]--;
  }

  // 副菜と禁止された組み合わせのソート
  qsort(b, m, sizeof(int) * 2, cmp_int_2d);
  qsort(cd, l, sizeof(int) * 2, cmp_int_2d);

  int ans = 0; // 最大価格
  // 最大価格の検索
  for (int i = 0; i < n; i++) { // 各主菜に対して
    // 副菜のインデックス（最後からスタート）
    int idx = m;
    // 組み合わせが見つかったかのフラグ
    int is_fin = 0;
    // まだ探索する副菜が残っているかつ組み合わせが見つかっていない間
    while (idx > 0 && is_fin <= 0) {
      // 副菜のインデックスを1つ前に移動
      idx--;
      // 禁止された組み合わせの範囲（二分探索用）
      int pos[2] = {0, l};
      // 禁止された組み合わせの範囲を絞り込む
      while (pos[1] - pos[0] > 1) {
        // 範囲の中間点
        int nxt = (pos[0] + pos[1]) / 2;
        if (cd[nxt][0] < i || (cd[nxt][0] == i && cd[nxt][1] <= b[idx][1])) {
          // 現在の主菜と副菜の組み合わせが、禁止された組み合わせよりも前、または同じ主菜で副菜のインデックスが小さい場合
          // 範囲の下限を中間点に設定
          pos[0] = nxt;
        } else {
          // それ以外の場合、範囲の上限を中間点に設定
          pos[1] = nxt;
        }
      }
      // 禁止された組み合わせに含まれないか確認
      if (l == 0 || cd[pos[0]][0] != i || cd[pos[0]][1] != b[idx][1]) {
        // 禁止リストが空、または現在の主菜と副菜の組み合わせが禁止された組み合わせに含まれていない場合
        // 組み合わせが見つかったとしてフラグを立てる
        is_fin = 1;
        // 価格を計算し、最大価格を更新
        if (a[i] + b[idx][0] > ans) {
          // 新しい最大価格を設定
          ans = a[i] + b[idx][0];
        }
      }
    }
  }
  // 結果の出力
  printf("%d\n", ans);
  return 0;
}
