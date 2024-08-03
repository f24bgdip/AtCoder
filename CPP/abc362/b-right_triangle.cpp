#include <iostream>

struct Point {
  int x;
  int y;
};

struct Vector {
  int x;
  int y;
};

// ベクトル内積計算
int dotProduct(const Vector &v1, const Vector &v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

// ベクトル計算
Vector createVector(const Point &p1, const Point &p2) {
  return {p2.x - p1.x, p2.y - p1.y};
}

// 直角三角形判定
bool isRightTriangle(const Point &A, const Point &B, const Point &C) {
  Vector AB = createVector(A, B);
  Vector BC = createVector(B, C);
  Vector CA = createVector(C, A);

  // 内積を計算して直角の有無をチェック
  return (dotProduct(AB, BC) == 0) || (dotProduct(BC, CA) == 0) ||
         (dotProduct(CA, AB) == 0);
}

int main() {
  Point A, B, C;

  std::cin >> A.x >> A.y;
  std::cin >> B.x >> B.y;
  std::cin >> C.x >> C.y;

  if (isRightTriangle(A, B, C)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
