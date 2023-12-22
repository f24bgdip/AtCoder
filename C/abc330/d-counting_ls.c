#include <stdio.h>
#include <string.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  char grid[N][N + 1];
  int row_o_cnt[N], col_o_cnt[N];
  memset(row_o_cnt, 0, sizeof(row_o_cnt));
  memset(col_o_cnt, 0, sizeof(col_o_cnt));

  for (int i = 0; i < N; i++) {
    if (scanf("%s", grid[i]) != 1)
      return -1;
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 'o') {
        row_o_cnt[i]++;
        col_o_cnt[j]++;
      }
    }
  }

  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 'o') {
        cnt += (row_o_cnt[i] - 1) * (col_o_cnt[j] - 1);
      }
    }
  }

  printf("%lld\n", cnt);
  return 0;
}
