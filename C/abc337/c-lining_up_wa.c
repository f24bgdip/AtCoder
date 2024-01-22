#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 各人の位置と最終的な順序を格納するための配列を確保
  int *position = (int *)malloc(N * sizeof(int));
  int *order = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    if (scanf("%d", &position[i]) != 1)
      return -1;
    order[i] = -1;
  }

  // 先頭にいる人を見つける
  int current = -1;
  for (int i = 0; i < N; i++) {
    if (position[i] == -1) {
      current = i;
      break;
    }
  }

  // 先頭から順番に並べる
  for (int i = 0; i < N; i++) {
    order[i] = current + 1; // 人の番号は1から始まるため、+1する
    current = position[current] - 1; // 次の人の位置を更新
  }

  // 結果を出力
  for (int i = 0; i < N; i++) {
    printf("%d ", order[i]);
  }
  printf("\n");

  // 使用したメモリを解放
  free(position);
  free(order);

  return 0;
}
