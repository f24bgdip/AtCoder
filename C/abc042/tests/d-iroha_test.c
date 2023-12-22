#include <stdio.h>
#include <stdlib.h>

#define TEST_MODE 0
#define MAX 199999
#define MOD 1000000007

long long fac[MAX];
long long finv[MAX];

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

// 前計算
void com_init() {
  long long inv[MAX];

  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for (int i = 2; i < MAX; i++) {
    // 階乗の計算
    fac[i] = fac[i - 1] * i % MOD;
    // 拡張ユークリッドの互除法による逆元計算
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    // 階乗の逆元
    finv[i] = finv[i - 1] * inv[i] % MOD;

#if 0
    // ログ出力
    if (i == 1 || i == 2 || i == 99998 || i == 99999 || i == 100000) {
      printf("com_init(): i = %d, fac[%d] = %lld, inv[%d] = %lld, finv[%d] = "
             "%lld\n",
             i, i, fac[i], i, inv[i], i, finv[i]);
  }
#endif
  }
}

// 組み合わせ計算（前計算済み）
long long mod_comb(int n, int k) {
  if (n < k)
    return 0;
  else if (n < 0 || k < 0)
    return 0;
#if 1
  printf("mod_comb(): n = %d, k = %d, fac[%d] = %lld, finv[%d] = %lld\n", n, k,
         n, fac[n], n - k, finv[n - k]);
#endif
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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

    // 前計算
    com_init();

    // printf("main(): fac[0] = %lld, finv[0] = %lld\n", fac[0], finv[0]);

    // 最終的な答えを格納する変数を初期化
    long long ans = 0;

    // iは山道のy座標を表す。山道の各y座標について処理を行う。
    for (int i = 0; i < H - A; i++) {

      // スタート地点から平地の入り口（B, i+1）までの移動方法の数を計算
      long long first_comb = mod_comb(B - 1 + i, i);
      printf("Start to Plain %d: n = %d, k = %d, first_comb = %lld\n", i,
             B - 1 + i, i, first_comb);

      // 平地の入り口からゴール地点までの移動方法の数を計算
      long long second_comb = mod_comb(W - B - 1 + H - 1 - i, H - 1 - i);
      printf("Plain to Goal %d: n = %d, k = %d, first_comb = %lld\n", i,
             W - B - 1 + H - 1 - i, H - 1 - i, second_comb);

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
