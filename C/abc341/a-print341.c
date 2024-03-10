#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  for (int i = 0; i < N; i++) {
    printf("10");
  }
  printf("1\n"); // 最後に1を追加

  return 0;
}
