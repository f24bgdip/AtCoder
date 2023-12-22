#include <stdio.h>

#define MAX_N 1001

int N, Q; // グリッドのサイズとクエリの数
long long cumulative_sum[MAX_N][MAX_N]; // 累積和を格納する配列

long long calculate_comlative_sum(int y, int x) {
  if (y < 0 || x < 0)
    return 0;

  // 番兵用の補正
  x++, y++;

  int x_rep = x / N; // 横方向の繰り返し回数
  int y_rep = y / N; // 縦方向の繰り返し回数
  int x_rem = x % N; // 横方向の余り
  int y_rem = y % N; // 縦方向の余り

  long long total = 0;
  total += cumulative_sum[N][N] * y_rep * x_rep; // 完全に含まれる領域
  total += cumulative_sum[y_rem][N] * x_rep;     // 上部の端
  total += cumulative_sum[N][x_rem] * y_rep;     // 左側の端
  total += cumulative_sum[y_rem][x_rem];         // 右下角の端数

  return total;
}

int main(void) {
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  // パターンPの読み込みと二次元累積和の計算
  char P[N + 1];
  for (int i = 1; i <= N; ++i) {

    if (scanf("%s", P) != 1)
      return -1;

    for (int j = 1; j <= N; ++j) {
      cumulative_sum[i][j] = cumulative_sum[i - 1][j] +
                             cumulative_sum[i][j - 1] -
                             cumulative_sum[i - 1][j - 1] + (P[j - 1] == 'B');
    }
  }

  // クエリの処理
  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    if (scanf("%d %d %d %d", &A, &B, &C, &D) != 4)
      return -1;

    // 指定された領域内の黒マスの総数を計算
    long long total = 0;
    total = calculate_comlative_sum(C, D);
    // 上側の余剰
    total -= calculate_comlative_sum(A - 1, D);
    // 左側の余剰
    total -= calculate_comlative_sum(C, B - 1);
    // 左上角の引き過ぎを補正
    total += calculate_comlative_sum(A - 1, B - 1);

    printf("%lld\n", total);
  }

  return 0;
}
