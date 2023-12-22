/*
 * With respect to the original solution.
 * This program is based on a solution example (#48216416)
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

typedef struct {
  int index;
  int price;
} Dish;

typedef struct {
  int main_dish_idx;
  int side_dish_idx;
} Meal;

int cmp_dish(const void *a, const void *b) {
  const Dish *dish_a = (const Dish *)a;
  const Dish *dish_b = (const Dish *)b;

  // 価格を昇順で比較
  if (dish_a->price < dish_b->price)
    return -1;
  if (dish_a->price > dish_b->price)
    return 1;

  // インデックスを昇順で比較
  if (dish_a->index < dish_b->index)
    return -1;
  if (dish_a->index > dish_b->index)
    return 1;

  return 0;
}

int main(void) {
  int N, M, L;
  if (scanf("%d %d %d", &N, &M, &L) != 3)
    return -1;

  int main_dish_price[N];
  int max_main_price = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &main_dish_price[i]) != 1)
      return -1;
    max_main_price = max(main_dish_price[i], max_main_price);
  }

  Dish side_dish[M];
  int max_side_price = 0;
  for (int i = 0; i < M; i++) {
    if (scanf("%d", &side_dish[i].price) != 1)
      return -1;
    side_dish[i].index = i;
    max_main_price = max(side_dish[i].price, max_main_price);
  }

  int max_price = 0;
  if (L == 0) {
    max_price = max_main_price + max_side_price;
    printf("%d\n", max_price);
    return 0;
  }

  Meal fbd_meal[L];
  for (int i = 0; i < L; i++) {
    if (scanf("%d %d", &fbd_meal[i].main_dish_idx,
              &fbd_meal[i].side_dish_idx) != 2)
      return -1;
    fbd_meal[i].main_dish_idx--;
    fbd_meal[i].side_dish_idx--;
  }

  qsort(side_dish, M, sizeof(Dish), cmp_dish);

  // 最大価格の検索
  for (int i = 0; i < N; i++) {
    // 副菜のインデックス（最後からスタート）
    int idx = M;
    // 組み合わせが見つかったかのフラグ
    int is_fin = 0;
    // まだ探索する副菜が残っているかつ組み合わせが見つかっていない間
    while (idx > 0 && is_fin <= 0) {
      // 副菜のインデックスを1つ前に移動
      idx--;
      // 禁止された組み合わせの範囲
      int pos[2] = {0, L};
      // 禁止された組み合わせの範囲を絞り込む
      while (pos[1] - pos[0] > 1) {
        // 範囲の中間点
        int next = (pos[0] + pos[1]) / 2;
        if (fbd_meal[next].main_dish_idx < i ||
            (fbd_meal[next].main_dish_idx == i &&
             fbd_meal[next].side_dish_idx <= side_dish[idx].index)) {
          // 現在の主菜と副菜の組み合わせが、禁止された組み合わせよりも前、または同じ主菜で副菜のインデックスが小さい場合
          // 範囲の下限を中間点に設定
          pos[0] = next;
        } else {
          // それ以外の場合、範囲の上限を中間点に設定
          pos[1] = next;
        }
      }
      // 禁止された組み合わせに含まれないか確認
      if (L == 0 || fbd_meal[pos[0]].main_dish_idx != i ||
          fbd_meal[pos[0]].side_dish_idx != side_dish[idx].index) {
        // 禁止リストが空、または現在の主菜と副菜の組み合わせが禁止された組み合わせに含まれていない場合
        // 組み合わせが見つかったとしてフラグを立てる
        is_fin = 1;
        // 価格を計算し、最大価格を更新
        if (main_dish_price[i] + side_dish[idx].price > max_price) {
          // 新しい最大価格を設定
          max_price = main_dish_price[i] + side_dish[idx].price;
        }
      }
    }
  }
  printf("%d\n", max_price);
  return 0;
}
