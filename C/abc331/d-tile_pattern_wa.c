#include <stdio.h>

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  char P[N][N + 1];
  int b_cnt[N][N];
  int row_b[N], col_b[N];

  for (int i = 0; i < N; i++) {
    if (scanf("%s", P[i]) != 1)
      return -1;
    row_b[i] = 0;
    col_b[i] = 0;
    // 各行各列の総数と二次元累積和の計算
    for (int j = 0; j < N; j++) {
      // 各行と各列の黒マスの総数
      row_b[i] += (P[i][j] == 'B');
      col_b[j] += (P[i][j] == 'B');

      // 現在のマスが黒かどうかを判定し、その結果をb_cntに格納する
      b_cnt[i][j] = (P[i][j] == 'B');

      // 累積和の計算：現在の行までの同じ列の黒マスの数を加算する
      if (i > 0)
        b_cnt[i][j] += b_cnt[i - 1][j];

      // 累積和の計算：現在の列までの同じ行の黒マスの数を加算する
      if (j > 0)
        b_cnt[i][j] += b_cnt[i][j - 1];

      // 重複して加算された部分（左上の隅の部分）を減算する
      if (i > 0 && j > 0)
        b_cnt[i][j] -= b_cnt[i - 1][j - 1];
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
    if ((C + 1) % N != 0) {
      for (int j = B; j < B + cols * N; j++) {
        total += col_b[j % N];
      }
    }

    // 右側の端の処理
    if ((D + 1) % N != 0) {
      for (int i = A; i <= C; i++) {
        total += row_b[i % N];
      }
    }

    printf("%lld\n", total);
  }

  return 0;
}
