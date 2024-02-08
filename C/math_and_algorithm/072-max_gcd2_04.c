#include <stdio.h>

int main() {
  int A = 101, B = 139; // 例として、A = 2, B = 4を使用
  int diff = B - A;

  printf("Using loop: for (int i = 1; i <= diff; ++i) with break\n");
  for (int i = 1; i <= diff; ++i) {
    int divisor = diff / i;
    if (i > divisor) {
      break; // iがdivisorより大きくなったらループを終了
    }
    printf("Divisor: %d\n", divisor);
  }

  printf("\nUsing loop: for (int i = 1; i * i <= diff; ++i)\n");
  for (int i = 1; i * i <= diff; ++i) {
    printf("Divisor: %d\n",
           diff / i); // ここではi * i <= diffの条件により、自動的にi >
                      // divisorとなる場合を避けている
  }

  return 0;
}
