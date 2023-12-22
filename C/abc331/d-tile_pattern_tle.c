#include <stdio.h>

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  char P[N][N + 1];
  int b_cnt[N][N];

  for (int i = 0; i < N; i++) {
    if (scanf("%s", P[i]) != 1)
      return -1;

    // 二次元累積和
    for (int j = 0; j <= N; ++j) {
      if (i == 0 || j == 0) {
        b_cnt[i][j] = 0;
      } else {
        b_cnt[i][j] = b_cnt[i - 1][j] + b_cnt[i][j - 1] - b_cnt[i - 1][j - 1] +
                      (pattern[i][j] == 'B');
      }
    }
  }

  while (Q--) {
    int A, B, C, D;
    if (scanf("%d %d %d %d", &A, &B, &C, &D) != 4)
      return -1;

    long long total = 0;

    // 完全に含まれるパターンPの領域の計算
    int rows = (C - A + 1) / N;
    int cols = (D - B + 1) / N;
    total += (long long)rows * cols * b_cnt[N - 1][N - 1];

    // 端の部分の処理
    // 下部の端の処理
    for (int i = A + rows * N; i <= C; i++) {
      // 現在の行がパターンP内でどの行に対応するかを計算
      int row = i % N;

      // 長方形領域の左側から、完全に含まれる列の終わりまでループ
      for (int j = B; j < B + cols * N; j++) {
        // 現在の列がパターンP内でどの列に対応するかを計算
        int col = j % N;

        // 対応するマスが黒マスであれば、カウントを1増やす
        if (P[row][col] == 'B') {
          total++;
        }
      }
    }

    // 右側の端の処理
    for (int i = A; i < A + rows * N; i++) {
      int row = i % N;
      for (int j = B + cols * N; j <= D; j++) {
        int col = j % N;
        if (P[row][col] == 'B') {
          total++;
        }
      }
    }

    // 右下の角の処理
    for (int i = A + rows * N; i <= C; i++) {
      int row = i % N;
      for (int j = B + cols * N; j <= D; j++) {
        int col = j % N;
        if (P[row][col] == 'B') {
          total++;
        }
      }
    }

    printf("%lld\n", total);
  }

  return 0;
}
