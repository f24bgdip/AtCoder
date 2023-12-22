// This code is based on 45438568.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST_MODE 0

struct TestCase {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  int expected;
};

struct TestCase testCases[] = {{3, 81, 49, 16, 24, 11, 31, 52, 1},
                               {29, 51, 56, 47, 92, 21, 3, 6, 0}};

typedef struct {
  long long x;
  long long y;
} Point;

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
  if (scanf("%lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y) != 4)
    return -1;
  if (scanf("%lld %lld %lld %lld", &c.x, &c.y, &d.x, &d.y) != 4)
    return -1;
#endif
    // 線分ABと点Cの外積
    long long AB_c = ((c.y - a.y) * (a.x - b.x)) - ((c.x - a.x) * (a.y - b.y));
    // 線分ABと点Dの外積
    long long AB_d = ((d.y - a.y) * (a.x - b.x)) - ((d.x - a.x) * (a.y - b.y));
    // 線分CDと点Aの外積
    long long CD_a = ((a.y - c.y) * (c.x - d.x)) - ((a.x - c.x) * (c.y - d.y));
    // 線分CDと点Bの外積
    long long CD_b = ((b.y - c.y) * (c.x - d.x)) - ((b.x - c.x) * (c.y - d.y));

    unsigned int result = 0;
    // 線分ABの両端が線分CDの異なる側にあるかをチェック
    if (((CD_a > 0) && (CD_b < 0)) || ((CD_a < 0) && (CD_b > 0)))
      // 線分CDの両端が線分ABの異なる側にあるかをチェック
      if (((AB_c > 0) && (AB_d < 0)) || ((AB_c < 0) && (AB_d > 0))) {
        result = 1; // 交差していると判定
      }

    if (CD_a == 0) {
      // 点AまたはBが線分CD上にあるかをチェック
      if (((c.x <= a.x) && (a.x <= d.x)) || ((d.x <= a.x) && (a.x <= c.x))) {
        // X座標が線分CDの範囲内か
        if (((c.y <= a.y) && (a.y <= d.y)) || ((d.y <= a.y) && (a.y <= c.y))) {
          // Y座標が線分CDの範囲内か
          // 端点が線分CD上にあり、交差していると判定
          result = 1;
        }
      }
    }
    if (CD_b == 0) {
      // 点AまたはBが線分CD上にあるかをチェック
      if (((c.x <= b.x) && (b.x <= d.x)) || ((d.x <= b.x) && (b.x <= c.x))) {
        // X座標が線分CDの範囲内か
        if (((c.y <= b.y) && (b.y <= d.y)) || ((d.y <= b.y) && (b.y <= c.y))) {
          // Y座標が線分CDの範囲内か
          // 端点が線分CD上にあり、交差していると判定
          result = 1;
        }
      }
    }

    if (AB_c == 0) {
      // 点CまたはDが線分AB上にあるかをチェック
      if (((a.x <= c.x) && (c.x <= b.x)) || ((b.x <= c.x) && (c.x <= a.x))) {
        // X座標が線分ABの範囲内か
        if (((a.y <= c.y) && (c.y <= b.y)) || ((b.y <= c.y) && (c.y <= a.y))) {
          // Y座標が線分ABの範囲内か
          // 端点が線分AB上にあり、交差していると判定
          result = 1;
        }
      }
    }
    if (AB_d == 0) {
      // 点CまたはDが線分AB上にあるかをチェック
      if (((a.x <= d.x) && (d.x <= b.x)) || ((b.x <= d.x) && (d.x <= a.x))) {
        // X座標が線分ABの範囲内か
        if (((a.y <= d.y) && (d.y <= b.y)) || ((b.y <= d.y) && (d.y <= a.y))) {
          // Y座標が線分ABの範囲内か
          // 端点が線分AB上にあり、交差していると判定
          result = 1;
        }
      }
    }
    printf((result == 1) ? "Yes\n" : "No\n");
#if TEST_MODE
    // テスト用のコード
    if (expected == result)
      printf("Test OK: first = %lld, Expected = %d, Actual = %d\n", a.x,
             expected, result);
    else
      printf("Test NG: first = %lld, Expected = %d, Actual = %d\n", a.x,
             expected, result);
  }
#else
// 通常のコード
#endif
}