#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 15
#define MAX_DIGIT_SUM 126
#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

// dp[i][j][s][k]
// i: 桁数（1ベース）
// j: 状態（1:大小関係が確定 0:確定していない）
// s: 桁和（1ベース）
// r: 桁和kで割った余り（余り0であれば、良い整数）
ll dp[MAX_DIGITS + 1][2][MAX_DIGIT_SUM + 1][MAX_DIGIT_SUM];

ll counter(int n) {
  // nと等しい正整数を数えることが面倒なので、
  // n未満を解とできるようにインクリメントする
  n++;
  // nを桁ごとに分割したいので、文字列に変換する
  char str_n[MAX_DIGITS + 1];
  sprintf(str_n, "%d", n);
  int m = strlen(str_n);
  ll count = 0;
  // 桁和でループ
  for (int k = 1; k <= MAX_DIGIT_SUM; k++) {
    // dp配列を初期化
    rep(i, m + 1) rep(j, 2) rep(s, k + 1) rep(r, k) dp[i][j][s][r] = 0;
    // 初期化
    // 何もしていない
    // 大小関係が確定していない
    // 桁和=0
    // 余り=0
    dp[0][0][0][0] = 1;
    // dp
    // i: 上の桁から決めていく
    // j: 大小関係が確定していないものから、決めていく
    // s: 桁和が同じようなものから、決めていく
    // r: kの倍数（余り0）であるものから、決めていく
    rep(i, m) rep(j, 2) rep(s, k + 1) rep(r, k) {
      // 桁になり得る値を試す
      rep(d, 10) {
        // 次の桁
        int ni = i + 1;
        // 状態
        int nj = j;
        // 桁和
        int ns = s + d;
        // 余り
        int nr = (r * 10 + d) % k;
        if (ns > k)
          continue;
        if (j == 0) {
          int digit = str_n[i] - '0';
          if (digit < d)
            // Nより大きいなら、対象外
            continue;
          if (digit > d)
            // Nより小さいなら、大小関係が確定
            nj = 1;
        }
        dp[ni][nj][ns][nr] += dp[i][j][s][r];
        // printf("dp[%d][%d][%d][%d]=%lld\n", i, j, s, r, dp[i][j][s][r]);
        // printf("dp[%d][%d][%d][%d]=%lld\n", ni, nj, ns, nr,
        // dp[ni][nj][ns][nr]);
      }
    }
    // 桁和1から126まで、その桁和で良い整数である個数を加算
    count += dp[m][1][k][0];
  }
  //
  return count;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  printf("%lld\n", counter(N));

  return 0;
}
