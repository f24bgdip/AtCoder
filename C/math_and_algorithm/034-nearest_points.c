#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 2次元配列を比較する関数
int cmp_int_2d(const void *a, const void *b) {
  int *a_ = (int *)a;
  int *b_ = (int *)b;

  // x
  if (a_[0] < b_[0])
    return -1;
  if (a_[0] > b_[0])
    return 1;
  // y
  if (a_[1] < b_[1])
    return -1;
  if (a_[1] > b_[1])
    return 1;
  return 0;
}

// 2点間の距離を計算
double distance(int a[2], int b[2]) {
  double dx = (double)a[0] - b[0];
  double dy = (double)a[1] - b[1];
  return sqrt(dx * dx + dy * dy);
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int P[N][2];
  for (int i = 0; i < N; i++) {
    if (scanf("%d %d", &P[i][0], &P[i][1]) != 2)
      return -1;
  }

  qsort(P, N, sizeof(int) * 2, cmp_int_2d);

  double min_dist = INFINITY;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (P[j][0] - P[i][0] > min_dist)
        break;
      double dist = distance(P[i], P[j]);
      if (dist < min_dist)
        min_dist = dist;
    }
  }

  printf("%.9lf\n", min_dist); // 小数点以下9桁まで表示

  return 0;
}
