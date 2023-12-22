#include <stdio.h>
#include <stdlib.h>

#define TEST_MODE 1
#define MAX 100000
#define MOD 1000000007

long long inv[MAX] = {0};

struct TestCase {
  int H, W, A, B;
  long long expected;
};

struct TestCase testCases[] = {
    {1, 100000, 1, 1, 0},
    {2, 3, 1, 1, 2},
    {2, 100000, 1, 1, 99999},
    {3, 3, 1, 1, 5},
    {3, 3, 1, 2, 3},
    {3, 3, 2, 1, 3},
    {3, 100000, 1, 1, 49964},
    {4, 4, 1, 1, 19},
    {4, 4, 1, 2, 16},
    {4, 4, 2, 1, 16},
    {4, 4, 2, 2, 10},
    {4, 4, 1, 3, 10},
    {4, 4, 3, 1, 10},
    {4, 4, 3, 3, 1},
    {4, 100000, 1, 1, 665533302},
    {5, 5, 1, 1, 69},
    {5, 5, 1, 2, 65},
    {5, 100000, 1, 1, 81608505},
    {6, 100000, 1, 1, 835395384},
    {7, 100000, 1, 1, 452482022},
    {8, 100000, 1, 1, 416696485},
    {9, 100000, 1, 1, 320647963},
    {10, 7, 3, 4, 3570},
    {10, 10, 4, 5, 33130},
    {99, 100000, 1, 1, 818536965},
    {100, 100, 44, 55, 796385587},
    {999, 100000, 1, 1, 746263012},
    {1000, 1000, 444, 555, 9549854},
    {9999, 9999, 1, 1, 399822955},
    {9999, 10000, 1, 1, 463972359},
    {9999, 100000, 1, 1, 2189129},
    {10000, 10000, 1, 1, 927944719},
    {10000, 10000, 4444, 5555, 234300332},
    {99999, 99999, 1, 1, 37711409},
    {100000, 9, 1, 1, 320647963},
    {100000, 9999, 1, 1, 2189129},
    {100000, 100000, 1, 1, 691090291},
    {100000, 100000, 1, 2, 690990292},
    {100000, 100000, 1, 3, 691040327},
    {100000, 100000, 1, 99999},
    {100000, 100000, 99999, 1},
    {100000, 100000, 11111, 22222, 364233526},
    {100000, 100000, 44444, 55555, 738162020},
    {100000, 100000, 99999, 99999, 1},
};

// 累乗計算（モジュラー演算付き）
long long mod_pow(long long x, long long y, long long mod) {
  long long res = 1;
  while (y > 0) {
    if (y & 1)
      res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}

// フェルマーの小定理を用いて、モジュラー逆元を計算
long long mod_inv(long long x, long long mod) {
  return mod_pow(x, mod - 2, mod);
}

// 組み合わせ（モジュラー演算付き）
long long mod_comb(long long n, long long k, long long mod) {
  long long res = 1;
  for (long long i = 0; i < k; i++) {
    res = res * (n - i) % mod;
    if (inv[i] == 0)
      inv[i] = mod_inv(i + 1, mod);
    res = res * inv[i] % mod;
  }

  return res;
}

int main() {
  int H, W, A, B;
#if TEST_MODE
  // テスト用のコード
  for (int i = 0; i < sizeof(testCases) / sizeof(struct TestCase); i++) {
    // テスト実行と結果の確認
    H = testCases[i].H;
    W = testCases[i].W;
    A = testCases[i].A;
    B = testCases[i].B;
    long long expected = testCases[i].expected; // 期待値も取得
#else
  // 通常のコード
  scanf("%d %d %d %d", &H, &W, &A, &B);
#endif

    // 最終的な答えを格納する変数を初期化
    long long ans = 0;

    // iは山道のy座標を表す。山道の各y座標について処理を行う。
    for (int i = 0; i < H - A; i++) {

      // スタート地点から平地の入り口（B, i+1）までの移動方法の数を計算
      long long first_comb = mod_comb(B - 1 + i, i, MOD);
      // printf("Start to Plain %d: n = %d, k = %d, first_comb = %lld\n", i, B -
      // 1 + i, i, first_comb);

      // 平地の入り口からゴール地点までの移動方法の数を計算
      long long second_comb = mod_comb(W - B - 1 + H - 1 - i, H - 1 - i, MOD);
      // printf("Plain to Goal %d: n = %d, k = %d, first_comb = %lld\n", i, W -
      // B - 1 + H - 1 - i, H - 1 - i, second_comb);

      // 2つの移動方法の数を掛け合わせる（MODで割る）
      long long temp = (first_comb * second_comb) % MOD;

      // 今までの答えに加算（MODで割る）
      ans = (ans + temp) % MOD;
    }

    printf("%lld\n", ans);

#if TEST_MODE
    // テスト用のコード
    if (expected == ans)
      printf("Test OK: Expected = %lld, Actual = %lld\n", expected, ans);
    else
      printf("Test NG: Expected = %lld, Actual = %lld\n", expected, ans);
  }
#else
  // 通常のコード
#endif

  return 0;
}
