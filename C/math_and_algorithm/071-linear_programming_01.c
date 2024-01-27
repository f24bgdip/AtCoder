#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x, y;
} Point;

// 2次元ベクトルの外積（z成分）
// 行列式が0の場合、2つの直線は平行（または同一）で交点を持たない
// 行列式が0でない場合、2つの直線は一点で交差する
double cross_product_2d(double a1, double a2, double b1, double b2) {
  return a1 * b2 - a2 * b1;
}
// 2つの直線の交点を計算する関数
Point get_intersection(double a1, double b1, double c1, double a2, double b2,
                       double c2) {
  Point p;
  // 行列式（determinant）の計算
  double det = cross_product_2d(a1, a2, b1, b2);

  if (det == 0) {
    // 行列式が0の場合、2つの直線は平行（または同一）で交点を持たない
    // 交点が存在しないことを示すために-1を代入
    p.x = p.y = -1;
  } else {
    // 行列式が0でない場合、2つの直線は一点で交差する
    p.x = (b2 * c1 - b1 * c2) / det; // x座標の交点を計算
    p.y = (a1 * c2 - a2 * c1) / det; // y座標の交点を計算
  }
  // 計算した交点を返す
  return p;
}

// 交点がすべての制約を満たすかをチェックする関数
int is_valid(Point p, double a[], double b[], double c[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] * p.x + b[i] * p.y > c[i]) {
      // 制約を満たさない
      return 0;
    }
  }
  // すべての制約を満たす
  return 1;
}

int main() {
  int n;
  // 制約条件の入力
  if (scanf("%d", &n) != 1)
    return -1;

  double a[500], b[500], c[500];
  for (int i = 0; i < n; i++) {
    if (scanf("%lf %lf %lf", &a[i], &b[i], &c[i]) != 3)
      return -1;
  }

  // x+yの最大値を保持する変数を初期化
  double maxSum = 0;

  // 全ての直線のペアについてループ
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // 2つの直線の交点を計算
      Point p = get_intersection(a[i], b[i], c[i], a[j], b[j], c[j]);

      // 交点がすべての制約を満たすか確認
      if (is_valid(p, a, b, c, n)) {
        // 交点が制約を満たす場合、x+yの値を計算
        double sum = p.x + p.y;

        // 現在の最大値より大きい場合は更新
        if (sum > maxSum) {
          maxSum = sum;
        }
      }
    }
  }
  // 最大値を出力
  printf("%f\n", maxSum);

  return 0;
}
