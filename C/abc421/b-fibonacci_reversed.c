/*
キーワード
フィボナッチ数列, 桁反転
*/
#include <stdio.h>
typedef unsigned long long ull;

static ull reverse(ull x) {
  ull r = 0;
  while (x > 0) {
    r = r * 10 + (x % 10);
    x /= 10;
  }

  return r;
}

int main(void) {
  ull X, Y;
  scanf("%llu %llu", &X, &Y);

  ull a1 = X, a2 = Y;
  for (int i = 3; i <= 10; ++i) {
    ull a3 = a1 + a2;
    ull rev_a3 = reverse(a3);
    a1 = a2;
    a2 = rev_a3;
  }

  printf("%llu\n", a2);

  return 0;
}
