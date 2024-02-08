#include <stdio.h>

// 最大公約数を求める
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int A, B;
  if (scanf("%d %d", &A, &B) != 2)
    return -1;

  int max_gcd = 1;
  for (int y = B; y > A; y--)
    // yの約数を探す

    for (int x = y - max_gcd; x >= A; x--) {

      // 最大値更新
      int current_gcd = gcd(x, y);
      if (max_gcd < current_gcd) {
        max_gcd = current_gcd;
      }
    }

  printf("%d\n", max_gcd);

  return 0;
}
