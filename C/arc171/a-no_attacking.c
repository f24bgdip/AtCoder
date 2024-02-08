#include <stdio.h>

int main() {
  int T;
  if (scanf("%d", &T) != 1)
    return -1;

  while (T--) {
    int N, A, B;
    if (scanf("%d %d %d", &N, &A, &B) != 3)
      return -1;

    // ルークとポーンの合計がチェス盤のマスの総数を超えるかチェック
    if (A + B > N * N) {
      printf("No\n");
      continue;
    }
    // ルークが使用できる行数を超えるかチェック
    if (A > N) {
      printf("No\n");
      continue;
    }
    // ルークを配置後、ポーンを配置するのに十分なスペースがあるかチェック
    if (B > (N - A) * (int)((N - A + 1) / 2)) {
      printf("No\n");
      continue;
    }
    // すべてのチェックを合格した場合、Yes
    printf("Yes\n");
  }

  return 0;
}
