#include <stdio.h>

// 最小値を更新する関数
void chmin(int *a, int b) {
  if (*a > b)
    *a = b;
}

// 最大値を更新する関数
void chmax(int *a, int b) {
  if (*a < b)
    *a = b;
}

// マージソートを行う関数
void merge_sort(int n, int x[]) {
  static int y[200001] = {};
  if (n <= 1)
    return;
  merge_sort(n / 2, &(x[0]));
  merge_sort((n + 1) / 2, &(x[n / 2]));

  int i, p, q;
  for (i = 0, p = 0, q = n / 2; i < n; i++) {
    if (p >= n / 2)
      y[i] = x[q++];
    else if (q >= n)
      y[i] = x[p++];
    else
      y[i] = (x[p] < x[q]) ? x[p++] : x[q++];
  }
  for (i = 0; i < n; i++)
    x[i] = y[i];
}

int main() {
  int i, N, K, A[5];
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++)
    scanf("%d", &(A[i]));
  merge_sort(N, A);

  int j, max = 0, q[5], head, tail = 0;
  for (i = 0; i < N; i = j) {
    // 同じ要素の連続する部分を見つける
    for (j = i; j < N && A[j] == A[i]; j++)
      // A[i] と同じ値を持つ最後の要素までインデックス j を進める
      ;

    // 最も頻度が高い要素の頻度 (max) を更新
    if (max < j - i) {
      max = j - i; // 新しい最大頻度を設定
      tail = 0; // 最大頻度の要素を保持する配列 q のインデックスをリセット
    }

    // 最大頻度の要素を配列 q に追加
    if (max == j - i)
      // 最大頻度の要素 A[i] を q に追加し、tail をインクリメント
      q[tail++] = A[i];
  }
  if (tail == 1) {
    // 最も頻度が高い要素が1つだけの場合
    printf("%lld\n", (long long)K * (N - max));
    return 0;
  }

  int min = q[tail - 1] - q[0];
  // 最も頻度が高い要素のうち、最小値と最大値の差を初期値として設定

  for (head = 0; head < tail - 1; head++) {
    // 最も頻度が高い要素を走査
    i = q[head];
    j = q[head + 1];
    chmin(&min, i - j + K);
    // 隣接する最も頻度が高い要素間の差のモジュロ K を計算し、最小値を更新
  }

  printf("%lld\n", (long long)K * (N - max) - min);
  fflush(stdout);

  return 0;
}
