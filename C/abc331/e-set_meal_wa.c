#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SHIFT 20 // 2^20 > 10^5

int cmp(const void *a, const void *b) {
  if (*(long long *)a < *(long long *)b)
    return -1;
  if (*(long long *)a > *(long long *)b)
    return 1;
  return 0;
}

int cmp_2d(const void *a, const void *b) {
  int *a_ = (int *)a;
  int *b_ = (int *)b;

  // 副菜の価格を降順で比較
  if (a_[0] > b_[0])
    return -1;
  if (a_[0] < b_[0])
    return 1;

  // インデックスは昇順で比較
  if (a_[1] < b_[1])
    return -1;
  if (a_[1] > b_[1])
    return 1;

  return 0;
}

int main(void) {
  int N, M, L;
  if (scanf("%d %d %d", &N, &M, &L) != 3)
    return -1;

  int main_dish[N];
  int max_main = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &main_dish[i]) != 1)
      return -1;
    if (main_dish[i] > max_main)
      max_main = main_dish[i];
  }

  int side_dish[M][2];
  int max_side = 0;
  for (int i = 0; i < M; i++) {
    if (scanf("%d", &side_dish[i][0]) != 1)
      return -1;
    side_dish[i][1] = i;
    if (side_dish[i][0] > max_side)
      max_side = side_dish[i][0];
  }

  int max_price = 0;
  if (L == 0) {
    max_price = max_main + max_side;
    printf("%d\n", max_price);
    return 0;
  }

  long long ng_meal[L];
  for (int i = 0; i < L; i++) {
    int c, d;
    if (scanf("%d %d", &c, &d) != 2)
      return -1;
    ng_meal[i] = ((long long)c << SHIFT) + d;
  }

  qsort(side_dish, M, sizeof(int) * 2, cmp_2d);
  // qsort(ng_meal, L, sizeof(int), cmp);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      long long meal = ((long long)(i + 1) << SHIFT) + (side_dish[j][1] + 1);
      if (!bsearch(&meal, ng_meal, L, sizeof(long long), cmp)) {
        int price = main_dish[i] + side_dish[j][0];
        if (price > max_price) {
          max_price = price;
          break;
        }
      }
    }
  }

  printf("%d\n", max_price);
  return 0;
}
