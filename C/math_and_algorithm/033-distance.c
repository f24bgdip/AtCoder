#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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
double cross_product(Vector a, Vector b) { return b.b * a.a - b.a * a.b; }

double distance(Point a, Point b) {
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
  Point A, B, C;
  if (scanf("%lf %lf", &A.x, &A.y) != 2)
    return -1;
  if (scanf("%lf %lf", &B.x, &B.y) != 2)
    return -1;
  if (scanf("%lf %lf", &C.x, &C.y) != 2)
    return -1;

  Vector BA = vector(B, A);
  Vector BC = vector(B, C);
  Vector CA = vector(C, A);
  Vector CB = vector(C, B);

  double dotBA_BC = dot_product(BA, BC);
  double dotCA_CB = dot_product(CA, CB);

  double shortext_distance;
  if (dotBA_BC < 0) {
    // 点Aが線分BCの延長線上の点Bに近い場合
    shortext_distance = distance(A, B);
  } else if (dotCA_CB < 0) {
    // 点Aが線分BCの延長線上の点Cに近い場合
    shortext_distance = distance(A, C);
  } else {
    // 点Aが線分BC上に最も近い場合
    Vector normal = calculate_normal_vector(B, C);
    double normal_projection = dot_product(normal, BA);
    double normal_squared = dot_product(normal, normal);
    double k = normal_projection / normal_squared;

    // 垂線の足までの距離計算
    Point H = {A.x - k * normal.a, A.y - k * normal.b};
    shortext_distance = distance(A, H);
  }
  printf("%lf\n", shortext_distance);

  return 0;
}
