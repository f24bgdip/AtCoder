#include <stdio.h>

int main(void) {
  int N;
  long long answer = 0;
  // 標準入力から整数Nを読み込む
  if (scanf("%d", &N) != 1)
    return -1;

  // 1からNまでの各iについてループ
  for (int i = 1; i <= N; i++) {
    // holdはN以下でiの倍数である数の個数
    long long hold = N / i;
    // 約数の総和を計算し、answerに加算
    // hold * (hold + 1) / 2 は、1からholdまでの和
    answer += (long long)(i) * ((hold) * (hold + 1) / 2);
  }

  // 計算された答えを出力
  printf("%lld", answer);
  return 0;
}
