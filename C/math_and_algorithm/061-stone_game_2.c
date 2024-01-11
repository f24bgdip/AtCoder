#include <stdio.h>

typedef long long ll;

int main() {
  ll N;
  if (scanf("%lld", &N) != 1)
    return -1;

  // N + 1 が2のべき乗であるかをチェック
  // ビット演算を使用して2のべき乗をチェックする方法は、N + 1
  // が2のべき乗であれば、そのバイナリ表現に1が1つだけ含まれるという特性に基づく
  if ((N + 1) & N) {
    // N + 1 が2のべき乗でなければ先手勝ち
    printf("First\n");
  } else {
    // N + 1 が2のべき乗であれば後手勝ち
    printf("Second\n");
  }

  return 0;
}
