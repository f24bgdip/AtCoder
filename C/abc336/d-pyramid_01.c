#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int max_pyramid_size(int n, int a[n]) {
  int left_height[n], right_height[n];
  for (int i = 0; i < n; i++)
    left_height[i] = 0, right_height[i] = 0;
  // 左側が階段になっているか？
  // 階段になっていれば、1ずつ増加する
  for (int i = 1; i < n; i++)
    left_height[i] = min(left_height[i - 1] + 1, a[i]);
  // 同様に右側が階段になっているか？
  // 追加した0を除き、右側から見ていく
  for (int i = n - 2; i >= 0; i--)
    right_height[i] = min(right_height[i + 1] + 1, a[i]);

  int top_height = 0;
  for (int i = 0; i < n; i++) {
    // 左側と右側が左右対称であるか？
    // 異なる場合、小さい方の山に合わせる
    int side_height = min(left_height[i], right_height[i]);
    // 一番高い山を記録
    top_height = max(top_height, side_height);
  }

  return top_height;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 配列のサイズnと山の高さhの関係： h=(n+1)/2
  // 数列の前後に0を追加することで、インデックスと高さを関係づけられる
  N += 2;
  int A[N];
  for (int i = 0; i < N; i++)
    A[i] = 0;

  for (int i = 1; i < N - 1; ++i) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }
  printf("%d\n", max_pyramid_size(N, A));

  return 0;
}
