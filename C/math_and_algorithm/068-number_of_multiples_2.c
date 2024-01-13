#include <stdio.h>

// 最大公約数を求める
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  long long N, K, V[10];
  if (scanf("%lld %lld", &N, &K) != 2)
    return -1;
  for (int i = 0; i < K; i++) {
    if (scanf("%lld", &V[i]) != 1)
      return -1;
  }

  long long ans = 0;
  // 外側のループでは、1から2^Kまでの全てのビットマスクを繰り返す
  // 各ビットマスクは異なるVの組み合わせを表す
  for (int mask = 1; mask < (1 << K); mask++) {
    // lcm_valは、現在のビットマスクに対応するVの値の最小公倍数を格納
    long long lcm_val = 1;
    // bits変数は、現在のビットマスクに含まれる1のビット数を数える
    int bits = 0;
    // 内側のループでは、各V[i]について、それが現在のビットマスクに含まれるかどうかを確認
    for (int i = 0; i < K; i++) {
      // ビットマスクにV[i]が含まれている場合
      if (mask & (1 << i)) {
        // lcm_valを更新
        // V[i]を含む新しいlcm_valの値を計算
        lcm_val = lcm(lcm_val, V[i]);
        // lcm_valがNを超えた場合、処理を中断
        // この組み合わせはN以下の整数に影響を与えないため
        if (lcm_val > N)
          break;
        // ビットが設定されているため、bitsをインクリメント
        bits++;
      }
    }
    // 全てのV[i]の組み合わせに対して、包除原理を適用
    if (bits % 2 == 1) {
      // 奇数個のV[i]を持つ組み合わせは、答えに加算
      ans += N / lcm_val;
    } else {
      // 偶数個のV[i]を持つ組み合わせは、答えから減算
      ans -= N / lcm_val;
    }
  }
  printf("%lld\n", ans);

  return 0;
}
