#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int freq[N];
  for (int i = 0; i < N; i++) {
    freq[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i != j) {
        int d = (A[i] - A[j] + K) % K;
        if (K - 1 - N > d)
          continue;
        freq[d]++;
      }
    }
  }

  // ここで freq 配列を出力または分析する
  for (int i = 0; i < K; i++) {
    printf("freq[%d] = %d\n", i, freq[i]);
  }

  return 0;
}
