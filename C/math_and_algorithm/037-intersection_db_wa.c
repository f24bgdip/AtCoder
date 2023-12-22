#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_MODE 0

struct TestCase {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  int expected;
};

struct TestCase testCases[] = {
    {7, 66, 0, 0, 82, 99, 36, 46, 0},    {8, 75, 3, 29, 94, 77, 26, 48, 0},
    {91, 94, 61, 6, 6, 79, 9, 30, 0},    {9, 2, 59, 21, 89, 9, 42, 97, 0},
    {75, 29, 70, 58, 80, 59, 56, 88, 0}, {34, 60, 70, 80, 37, 96, 80, 80, 0},
    {91, 42, 86, 49, 73, 48, 31, 82, 0}, {2, 90, 55, 92, 99, 98, 89, 27, 0},
    {79, 59, 85, 59, 18, 41, 0, 5, 0},   {53, 70, 37, 42, 66, 18, 23, 9, 0},
    {99, 24, 67, 22, 62, 76, 71, 91, 0}, {33, 85, 50, 12, 52, 23, 83, 7, 0},
    {19, 47, 51, 62, 71, 23, 5, 79, 1},  {72, 94, 18, 29, 94, 59, 28, 93, 1},
    {36, 47, 16, 98, 23, 39, 90, 9, 0},  {24, 92, 21, 77, 67, 4, 36, 86, 0},
    {51, 87, 0, 75, 62, 6, 54, 35, 0},   {52, 72, 64, 46, 84, 92, 40, 20, 1},
    {39, 8, 18, 15, 99, 60, 24, 23, 0},  {4, 45, 52, 71, 2, 88, 10, 53, 0},
    {30, 69, 31, 39, 44, 42, 83, 32, 0}, {83, 16, 34, 17, 22, 38, 67, 50, 0},
    {27, 97, 25, 89, 62, 75, 25, 86, 0}, {99, 52, 18, 91, 17, 82, 85, 47, 0},
    {51, 16, 39, 47, 59, 22, 79, 42, 0}, {90, 65, 59, 12, 3, 27, 15, 31, 0},
    {24, 40, 20, 38, 16, 97, 76, 15, 0}, {2, 46, 58, 19, 28, 44, 19, 80, 0},
    {12, 10, 27, 71, 32, 59, 14, 74, 1}, {24, 25, 38, 28, 4, 53, 11, 81, 0},
    {92, 94, 37, 66, 51, 13, 66, 67, 0}, {68, 65, 0, 55, 35, 31, 11, 84, 1},
    {22, 24, 47, 75, 99, 20, 0, 42, 1},  {26, 63, 15, 23, 56, 81, 38, 1, 0},
    {27, 75, 67, 79, 88, 85, 98, 56, 0}, {51, 50, 11, 38, 82, 75, 23, 4, 0},
    {99, 70, 32, 98, 42, 32, 93, 69, 0}, {95, 60, 44, 3, 94, 82, 4, 21, 0},
    {9, 23, 0, 97, 9, 98, 5, 12, 1},     {1, 68, 50, 83, 95, 25, 87, 95, 0},
    {71, 97, 81, 1, 38, 11, 69, 54, 0},  {51, 34, 55, 56, 75, 48, 17, 61, 1},
    {86, 73, 45, 44, 79, 42, 97, 43, 0}, {52, 88, 66, 20, 97, 68, 68, 20, 0},
    {65, 49, 21, 56, 12, 42, 62, 63, 1}, {76, 17, 20, 52, 66, 89, 65, 4, 1},
    {14, 62, 0, 93, 56, 98, 36, 61, 0},  {38, 55, 81, 87, 75, 2, 8, 41, 0},
    {3, 81, 49, 16, 24, 11, 31, 52, 1},  {29, 51, 56, 47, 92, 21, 3, 6, 0}};

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
double cross_product_vector(Vector a, Vector b) {
  return b.b * a.a - b.a * a.b;
}
double cross_product_point(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 使用条件: cross_product == 0 であること
int is_overlap(Point a, Point b, Point c) {
  return (a.x <= c.x && c.x <= b.x || a.x >= c.x && c.x >= b.x) &&
         (a.y <= c.y && c.y <= b.y || a.y >= c.y && c.y >= b.y);
}

double distance(Point a, Point b) {
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(void) {
  Point a, b, c, d;
#if TEST_MODE
  // テスト用のコード
  for (int i = 0; i < sizeof(testCases) / sizeof(struct TestCase); i++) {
    a.x = testCases[i].x1;
    a.y = testCases[i].y1;
    b.x = testCases[i].x2;
    b.y = testCases[i].y2;
    c.x = testCases[i].x3;
    c.y = testCases[i].y3;
    d.x = testCases[i].x4;
    d.y = testCases[i].y4;
    int expected = testCases[i].expected; // 期待値も取得
#else

  if (scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y) != 4)
    return -1;
  if (scanf("%lf %lf %lf %lf", &c.x, &c.y, &d.x, &d.y) != 4)
    return -1;
#endif
    double AB_c = cross_product_point(a, b, c);
    double AB_d = cross_product_point(a, b, d);
    double CD_a = cross_product_point(c, d, a);
    double CD_b = cross_product_point(c, d, b);

    // printf("AB_c = %.9lf, AB_d = %.9lf\n", AB_c, AB_d);
    // printf("CD_a = %.9lf, CD_b = %.9lf\n", CD_a, CD_b);

    int result = 0;
    if ((AB_c > 0 && AB_d < 0) || (AB_c < 0 && AB_d > 0))
      if ((CD_a > 0 && CD_b < 0) || (CD_a < 0 && CD_b > 0))
        // 交差していると判定
        result = 1;

    bool overlap = false;
    if (AB_c == 0 && is_overlap(a, b, c))
      overlap = true;
    if (AB_d == 0 && is_overlap(a, b, d))
      overlap = true;
    if (CD_a == 0 && is_overlap(c, d, a))
      overlap = true;
    if (CD_b == 0 && is_overlap(c, d, b))
      overlap = true;
    if (overlap)
      // 重なっている場合
      result = 1;

    printf((result == 1) ? "Yes\n" : "No\n");
#if TEST_MODE
    // テスト用のコード
    if (expected == result)
      printf("Test OK: first = %lf, Expected = %d, Actual = %d\n", a.x,
             expected, result);
    else
      printf("Test NG: first = %lf, Expected = %d, Actual = %d\n", a.x,
             expected, result);
  }
#else
  // 通常のコード
#endif
  return 0;
}
