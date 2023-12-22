#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 5

typedef struct {
  long long int x, y;
} Point;

int compare(const void *a, const void *b) {
  Point *point_a = (Point *)a;
  Point *point_b = (Point *)b;
  return point_a->y - point_b->y;
}

int main() {
  long long int H, W, N;
  if (scanf("%lld %lld %lld", &H, &W, &N) != 3)
    return -1;

  Point coordinates[MAX_N * 9]; // 黒塗りマスごとに最大9つの座標を格納
  int count = 0;                // 座標データのカウンタ

  for (long long int i = 0; i < N; i++) {
    long long int a, b;
    if (scanf("%lld %lld", &a, &b) != 2)
      return -1;

    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        long long int x = a + dx;
        long long int y = b + dy;
        if (x >= 2 && x <= H - 1 && y >= 2 && y <= W - 1) {
          coordinates[count].x = x;
          coordinates[count].y = y;
          count++;
        }
      }
    }
  }

  return 0;
}
