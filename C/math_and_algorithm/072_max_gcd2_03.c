#include <stdio.h>

// ユークリッドの互除法による最大公約数（GCD）の計算
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int A, B;
  scanf("%d %d", &A, &B);

  int answer = 1;   // 最小のGCDは常に1
  int diff = B - A; // AとBの差

  for (int i = 2; i * i <= diff; ++i) {
    if (diff % i == 0) {
      // iがdiffの約数である場合、それをGCDの候補としてチェック
      if (gcd(A + i - A % i, B) == i) {
        answer = answer > i ? answer : i;
      }
      // diff / i もdiffの約数であるため、それもチェック
      int divisor = diff / i;
      if (gcd(A + divisor - A % divisor, B) == divisor) {
        answer = answer > divisor ? answer : divisor;
      }
    }
  }
  // diff自体が約数である場合もチェック
  if (gcd(A + diff - A % diff, B) == diff) {
    answer = answer > diff ? answer : diff;
  }

  printf("%d\n", answer);
  return 0;
}
