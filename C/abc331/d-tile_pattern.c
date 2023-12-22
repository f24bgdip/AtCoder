#include <stdio.h>
#include <string.h>

int min(int a, int b) { return (a < b) ? a : b; }

// (0, 0)を基準として、領域内の黒マスを数える
int count_black(int N, int b_cnt[N][N], int bottom, int right) {
  int total = 0;

  // パターンPが完全に含まれる領域の計算
  int p_cnt_row = bottom / N;
  int p_cnt_col = right / N;
  total += (long long)p_cnt_row * p_cnt_col * b_cnt[N - 1][N - 1];

  // 左側の残り
  leftside_bottom = bottom;
  leftside_right = right - p_cnt_col * N;

  // 上側の残り
  upper_bottom = bottom - p_cnt_row * N;
  upper_right = right - p_cnt_col * N;

  // 
  total += b_cnt[min(N - 1, bottom)][min(N - 1, right)];

  if (bottom > top)
    total += count_black(N, b_cnt, 0, left, bottom, right);
  if (right > left)
    total += count_black(N, b_cnt, top, 0, bottom, right);
  if (bottom > top && right > left)
    total -= count_black(N, b_cnt, top, 0, bottom, right);

  return total;
}

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  char P[N][N + 1];
  int b_cnt[N][N];
  int row_b[N], col_b[N];

  memset(row_b, 0, sizeof(row_b));
  memset(col_b, 0, sizeof(col_b));

  for (int i = 0; i < N; i++) {
    if (scanf("%s", P[i]) != 1)
      return -1;
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

    // 端の部分の処理
    // 下部の端の処理
    for (int i = A + p_cnt_row * N; i <= C; i++) {
      int row = i % N;
      // 完全に含まれる列の終わりまでの行総和を加算
      total += p_cnt_col * row_b[row];
    }

    // 右側の端の処理
    for (int j = B + p_cnt_col * N; j <= D; j++) {
      int col = j % N;
      // 完全に含まれる行の終わりまでの列総和を加算
      total += p_cnt_row * col_b[col];
    }

    // 右下角の端数の処理
    int row_remainder = (C - A + 1) % N;
    int col_remainder = (D - B + 1) % N;

    int top = (A + p_cnt_row) % N;
    int left = (B + p_cnt_col) % N;
    int bottom = (top + row_remainder) % N;
    int right = (left + col_remainder) % N;

    total += count_black(N, b_cnt, top, left, bottom, right);

    printf("%lld\n", total);
  }

  return 0;
}
