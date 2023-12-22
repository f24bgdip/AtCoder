#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "d-abc_puzzle.h"

struct TestCase {
  int N;
  std::string R;
  std::string C;
  bool expected;
};

class SolveTest : public ::testing::TestWithParam<TestCase> {};

// ヘルパー関数を定義します。
bool execute_solve(int N, const std::string &R, const std::string &C) {
  test_input(N, R, C);
  std::vector<std::string> grid(N, std::string(N, ' '));
  std::vector<std::vector<int>> abc_counts(N, std::vector<int>(3, 0));
  return solve(grid, abc_counts, 0);
}

// パラメータ化されたテスト関数を定義します。
TEST_P(SolveTest, HandlesInputCorrectly) {
  TestCase test_case =
      GetParam(); // 現在のテストケースのインスタンスを取得します。
  EXPECT_EQ(test_case.expected,
            execute_solve(test_case.N, test_case.R, test_case.C));
}

INSTANTIATE_TEST_SUITE_P(
    TestWithParameters, SolveTest,
    ::testing::Values(
        TestCase{.N = 3, .R = "ABC", .C = "ACB", .expected = true},
        TestCase{.N = 4, .R = "ABCA", .C = "BCAB", .expected = true},
        TestCase{.N = 4, .R = "ACBA", .C = "BACB", .expected = true},
        TestCase{.N = 4, .R = "BCAC", .C = "ABAB", .expected = true},
        TestCase{.N = 4, .R = "CABC", .C = "CABA", .expected = true},
        TestCase{.N = 4, .R = "ABAB", .C = "CBCB", .expected = true}
        // Add more test cases as needed
        ));