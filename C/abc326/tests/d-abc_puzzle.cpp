#include <iostream>
#include <string>
#include <vector>

int N;
std::string R, C;

std::string patterns[3][20] = {
    {"ABC  ", "AB C ", "AB  C", "ACB  ", "AC B ", "AC  B", "A BC ",
     "A B C", "A CB ", "A C B", "A  BC", "A  CB", " ABC ", " AB C",
     " ACB ", " AC B", " A BC", " A CB", "  ABC", "  ACB"},
    {"BAC  ", "BA C ", "BA  C", "BCA  ", "BC A ", "BC  A", "B AC ",
     "B A C", "B CA ", "B C A", "B  AC", "B  CA", " BAC ", " BA C",
     " BCA ", " BC A", " B AC", " B CA", "  BAC", "  BCA"},
    {"CAB  ", "CA B ", "CA  B", "CBA  ", "CB A ", "CB  A", "C AB ",
     "C A B", "C BA ", "C B A", "C  AB", "C  BA", " CAB ", " CA B",
     " CBA ", " CB A", " C AB", " C BA", "  CAB", "  CBA"}};

#define TEST 1

struct TestCase {
  int N;
  std::string R;
  std::string C;
  bool expected;
};

// テストケースのデータを設定
struct TestCase testCases[] = {
    {.N = 3, .R = "ABC", .C = "ACB", .expected = "No"},
    {.N = 4, .R = "ABCA", .C = "BCAB", .expected = ""},
    {.N = 4, .R = "ACBA", .C = "BACB", .expected = ""},
    {.N = 4, .R = "BCAC", .C = "ABAB", .expected = ""},
    {.N = 4, .R = "CABC", .C = "CABA", .expected = ""},
    {.N = 4, .R = "ABAB", .C = "CBCB", .expected = ""}};

void test_input(int n, std::string r, std::string c) {
  std::cout << n << std::endl;
  std::cout << r << " " << c << std::endl;

  N = n;
  R = r;
  C = c;
}

bool check(const std::vector<std::string> &grid, int row) {
  for (int col = 0; col < N; ++col) {
    char top_c = ' ';
    int cnt_a = 0, cnt_b = 0, cnt_c = 0;
    for (int r = 0; r <= row; ++r) {
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
    if (row == N - 1) {
      if (cnt_a != 1 || cnt_b != 1 || cnt_c != 1)
        return false;
    } else {
      if (cnt_a > 1 || cnt_b > 1 || cnt_c > 1)
        return false;
    }
  }
  return true;
}

bool solve(std::vector<std::string> &grid,
           std::vector<std::vector<int>> &abc_counts, int row) {
  std::cout << "Entering solve with row = " << row << std::endl;
  if (row == N) {
    return true;
  }

  int patternIndex = (R[row] == 'A') ? 0 : (R[row] == 'B') ? 1 : 2;

  for (const auto &pattern : patterns[patternIndex]) {
    grid[row] = pattern;
    if (check(grid, row) == false) {
      continue;
    }
    if (solve(grid, abc_counts, row + 1)) {
      return true;
    }
  }

  return false;
}

int main() {
#if TEST
  // テスト用のコード
  for (int i = 0; i < sizeof(testCases) / sizeof(struct TestCase); i++) {
    // テスト実行と結果の確認

    test_input(n, r, c); // Set global variables
#else
  std::cin >> N >> R >> C;
#endif

    std::vector<std::string> grid(N, std::string(N, ' '));
    std::vector<std::vector<int>> abc_counts(N, std::vector<int>(3, 0));

    if (solve(grid, abc_counts, 0)) {
      for (const auto &line : grid) {
        std::cout << line << std::endl;
      }
      std::cout << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }

#if TEST
  }
#endif
  return 0;
}
