#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  double a;
  double b;
} Vector;

Vector vector(Point A, Point B) {
  Vector v;
  v.a = B.x - A.x;
  v.b = B.y - A.y;
  return v;
}

// ベクトルを法線ベクトルに変換
Vector convert_normal_vector(Vector v) {
  Vector normal;
  normal.a = -v.b;
  normal.b = v.a;
  return normal;
}

// 2点に対する法線ベクトルを計算
Vector calculate_normal_vector(Point a, Point b) {
  Vector normal;
  normal.a = b.y - a.y;
  normal.b = a.x - b.x;
  return normal;
}

double dot_product(Vector a, Vector b) { return a.a * b.a + a.b * b.b; }

// 2次元ベクトルの外積（z成分）
// 行列式が0の場合、2つの直線は平行（または同一）で交点を持たない
// 行列式が0でない場合、2つの直線は一点で交差する
double cross_product_vector(Vector a, Vector b) {
  return b.b * a.a - b.a * a.b;
}

double cross_product_point(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double cross_product_2d(double a1, double a2, double b1, double b2) {
  return a1 * b2 - a2 * b1;
}

// 使用条件: cross_product == 0 であること
int is_overlap(Point a, Point b, Point c) {
  return (a.x <= c.x && c.x <= b.x || a.x >= c.x && c.x >= b.x) &&
         (a.y <= c.y && c.y <= b.y || a.y >= c.y && c.y >= b.y);
}

double distance(Point a, Point b) {
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

#define EPSILON 1e-9
bool is_zero(double value) { return fabs(value) < EPSILON; }

int main(void) {
  int N = 4;
  Point a, b, c, d;
  if (scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y) != 4)
    return -1;
  if (scanf("%lf %lf %lf %lf", &c.x, &c.y, &d.x, &d.y) != 4)
    return -1;

  double AB_c = cross_product_point(a, b, c);
  double AB_d = cross_product_point(a, b, d);
  double CD_a = cross_product_point(c, d, a);
  double CD_b = cross_product_point(c, d, b);

  printf("AB_c = %.9lf, AB_d = %.9lf\n", AB_c, AB_d);
  printf("CD_a = %.9lf, CD_b = %.9lf\n", CD_a, CD_b);

  if (AB_c * AB_d < 0 && CD_a * CD_b < 0) {
    // 交差している場合
    printf("Yes\n");
    return 0;
  } else {
    bool overlap = false;
    if ((is_zero(AB_c) && is_overlap(a, b, c)) ||
        (is_zero(AB_d) && is_overlap(a, b, d)) ||
        (is_zero(CD_a) && is_overlap(c, d, a)) ||
        (is_zero(CD_b) && is_overlap(c, d, b)))
      overlap = true;

    if (overlap)
      // 重なっている場合
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
