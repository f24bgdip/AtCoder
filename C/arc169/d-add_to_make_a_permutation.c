#include <stdio.h>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int A[N];
  int count[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    count[i] = 0;
  }

  // 各要素の出現回数をカウント
  for (int i = 0; i < N; i++) {
    count[A[i]]++;
  }

  int missing = 0, excess = 0;
  for (int i = 0; i < N; i++) {
    if (count[i] == 0) {
      missing++; // 欠けている要素
    } else if (count[i] > 1) {
      excess += count[i] - 1; // 重複している要素
    }
  }

  // 欠けている要素を補填するための操作回数
  int operations = (missing + M - 1) / M;

  // 重複している要素を処理するための操作回数
  operations += (excess + M - 1) / M;

  printf("%d\n", operations);
  return 0;
}
