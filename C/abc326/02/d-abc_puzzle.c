#include <stdbool.h>
#include <stdio.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;

const char patterns[3][20] = {
    {"ABC  ", "AB C ", "AB  C", "ACB  ", "AC B ", "AC  B", "A BC ",
     "A B C", "A CB ", "A C B", "A  BC", "A  CB", " ABC ", " AB C",
     " ACB ", " AC B", " A BC", " A CB", "  ABC", "  ACB"},
    {"BAC  ", "BA C ", "BA  C", "BCA  ", "BC A ", "BC  A", "B AC ",
     "B A C", "B CA ", "B C A", "B  AC", "B  CA", " BAC ", " BA C",
     " BCA ", " BC A", " B AC", " B CA", "  BAC", "  BCA"},
    {"CAB  ", "CA B ", "CA  B", "CBA  ", "CB A ", "CB  A", "C AB ",
     "C A B", "C BA ", "C B A", "C  AB", "C  BA", " CAB ", " CA B",
     " CBA ", " CB A", " C AB", " C BA", "  CAB", "  CBA"}};

bool check(int current_row, char pattern) {
  for (int col = 0; col < N; ++col) {
    char top_c = ' ';
    int cnt_a = 0, cnt_b = 0, cnt_c = 0;
    for (int r = 0; r <= current_row; ++r) {
      char c = grid[r][col];
      if (top_c == ' ' && c != ' ') {
        top_c = c;
      }
      if (c == 'A')
        cnt_a++;
      if (c == 'B')
        cnt_b++;
      if (c == 'C')
        cnt_c++;
    }
    // 枝刈り1:
    // 最も上にある文字がCの文字と一致するか、または空白でなければ、条件を満たさない
    if (top_c != ' ' && top_c != C[col]) {
      return false;
    }
    // 枝刈り2: 各列にA, B, Cがちょうど1個ずつ含まれるかを確認
    if (current_row == N - 1) {
      if (cnt_a != 1 || cnt_b != 1 || cnt_c != 1)
        return false;
    } else {
      if (cnt_a > 1 || cnt_b > 1 || cnt_c > 1)
        return false;
    }
  }
  return true;
}

bool easy_as_abc(int, n, char rc[2][n + 1], board[n][n], col_flag[n],
                 int currrent_row) {
  if (currrent_row == n)
    // 条件を満たすか確認
    return true;

  int group_id = (R[row] == 'A') ? 0 : (R[row] == 'B') ? 1 : 2;
  rep(i, 20) {
    if (check(currrent_row, patterns[group_id][i], col_flag) == false) {
      continue;
    }
    if (solve(grid, abc_counts, row + 1)) {
      return true;
    }
  }
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  char RC[2][N + 1];
  rep(i, 2) if (scanf("%s", RC[i]) != 1) return -1;

  char board[N][N];
  int col_flag[N];
  rep(i, n) col_flag[i] = 0;
  bool is_solved = easy_as_abc(N, RC, board, col_flag, 0);

  if (true) {
    printf("Yes\n");
    rep(i, N) {
      //
    }
  } else {
    printf("No\n");
  }

  return 0;
}
