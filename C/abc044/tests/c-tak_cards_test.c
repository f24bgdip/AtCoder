#include <limits.h>
#include <stdio.h>

#define MAX_N 50
#define MAX_A 50
#define MAX_SUM (MAX_N * MAX_A)

#define TEST_MODE 1

struct TestCase {
  int n, a;
  int x[MAX_N];
  long long expected;
};

// テストケースのデータを設定
struct TestCase testCases[] = {
    {.n = 50,
     .a = 40,
     .x = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
           18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
           35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
     .expected = 928381},
    {.n = 50,
     .a = 50,
     .x = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
           50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
           50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50},
     .expected = 2251799813685197}};

long long dp[MAX_N + 1][MAX_N + 1][MAX_N * MAX_A + 1];

int main(void) {
  int n, a;
  int x[MAX_N];

#if TEST_MODE
  // テスト用のコード
  for (int i = 0; i < sizeof(testCases) / sizeof(struct TestCase); i++) {
    // テスト実行と結果の確認
    n = testCases[i].n;
    a = testCases[i].a;
    for (int j = 0; j < n; j++) {
      x[j] = testCases[i].x[j];
    }
    long long expected = testCases[i].expected;

#else
  // 通常のコード
  scanf("%d %d", &n, &a);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
#endif

    // 初期化
    dp[0][0][0] = 1;

    // DPテーブルを更新
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= MAX_SUM; ++k) {
          if (dp[i][j][k]) {
            // カードiを選ばない場合
            dp[i + 1][j][k] += dp[i][j][k];
            // カードiを選ぶ場合
            if (dp[i][j][k] > LLONG_MAX - dp[i + 1][j + 1][k + x[i]]) {
              // Overflow detected
              printf("Overflow\n");
            } else {
              dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
            }
          }
        }
      }
    }

    // 結果を計算
    long long result = 0;
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k <= MAX_SUM; ++k) {
        if (j * a == k) {
          result += dp[n][j][k];
        }
      }
    }

    printf("%lld\n", result);

#if TEST_MODE
    // テスト用のコード
    if (expected == result)
      printf("Test OK: Expected = %lld, Actual = %lld\n", expected, result);
    else
      printf("Test NG: Expected = %lld, Actual = %lld\n", expected, result);
  }
#else
  // 通常のコード
#endif

  return 0;
}
