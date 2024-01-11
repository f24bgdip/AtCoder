#include <stdio.h>

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // N = 4 の場合は後手必勝
  // N が4の倍数の場合、先手は常に負ける
  // 後手は取った石の数を4から引いた数を取ることで、先手に常に4の倍数を残すことができる
  // N が4の倍数でない場合、先手は勝つ
  // 先手は初手で N mod 4 の数を取ることで、残りを4の倍数にすることができる
  if (N % 4 == 0) {
    printf("%s\n", "Second");
  } else {
    printf("%s\n", "First");
  }

  return 0;
}
