#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// 点を表す構造体
typedef struct {
  ll x, y;
} Point;

// Point型の比較関数（qsort用）
int compare(const void *a, const void *b) {
  Point *point1 = (Point *)a;
  Point *point2 = (Point *)b;
  if (point1->x < point2->x)
    return -1;
  if (point1->x > point2->x)
    return 1;
  return 0;
}

int main() {
  ll N, K;
  if (scanf("%lld %lld", &N, &K) != 2)
    return -1;

  Point *points = (Point *)malloc(N * sizeof(Point));

  for (ll i = 0; i < N; ++i) {
    if (scanf("%lld %lld", &points[i].x, &points[i].y) != 2)
      return -1;
  }

  // 点をx座標に基づいてソート
  qsort(points, N, sizeof(Point), compare);

  ll answer = LLONG_MAX;
  for (ll i = 0; i < N; ++i) {
    for (ll j = i + K - 1; j < N; ++j) {
      // 選択されたx座標の範囲内の点のy座標を集める
      ll *y_values = (ll *)malloc((j - i + 1) * sizeof(ll));
      for (ll k = i; k <= j; ++k) {
        y_values[k - i] = points[k].y;
      }
      // y座標をソート
      qsort(y_values, j - i + 1, sizeof(ll), compare);
      // y座標のペアに対してループし、最小面積を計算
      for (ll y = 0; y <= (j - i + 1) - K; ++y) {
        ll width = points[j].x - points[i].x;
        ll height = y_values[y + K - 1] - y_values[y];
        // オーバーフローの可能性をチェック
        if (width <= LLONG_MAX / height) {
          ll area = width * height;
          if (area < answer)
            answer = area;
        }
      }
      free(y_values);
    }
  }

  printf("%lld\n", answer);
  free(points);

  return 0;
}
