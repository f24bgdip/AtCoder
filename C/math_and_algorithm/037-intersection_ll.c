#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long x;
  long long y;
} Point;

long long cross_product_point(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 使用条件: cross_product == 0 であること
int is_overlap(Point a, Point b, Point c) {
  return (a.x <= c.x && c.x <= b.x || a.x >= c.x && c.x >= b.x) &&
         (a.y <= c.y && c.y <= b.y || a.y >= c.y && c.y >= b.y);
}

int main(void) {
  Point a, b, c, d;
  if (scanf("%lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y) != 4)
    return -1;
  if (scanf("%lld %lld %lld %lld", &c.x, &c.y, &d.x, &d.y) != 4)
    return -1;

  long long AB_c = cross_product_point(a, b, c);
  long long AB_d = cross_product_point(a, b, d);
  long long CD_a = cross_product_point(c, d, a);
  long long CD_b = cross_product_point(c, d, b);

  // printf("AB_c = %lld, AB_d = %lld\n", AB_c, AB_d);
  // printf("CD_a = %lld, CD_b = %lld\n", CD_a, CD_b);

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
  return 0;
}
