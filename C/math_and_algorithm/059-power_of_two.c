#include <stdio.h>

int main() {
  long long N;
  if (scanf("%lld", &N) != 1)
    return -1;

  // 2の累乗の一の位のパターンは 2, 4, 8, 6 と周期的に繰り返される
  // N % 4 = 0 の場合、6
  // N % 4 = 1 の場合、2
  // N % 4 = 2 の場合、4
  // N % 4 = 3 の場合、8
  int last_digits[4] = {6, 2, 4, 8};

  // Nが1の場合は特別に処理する
  if (N == 1) {
    printf("2\n");
  } else {
    // N を 4 で割った余りを使用して、対応する一の位を出力
    printf("%d\n", last_digits[N % 4]);
  }

  return 0;
}
