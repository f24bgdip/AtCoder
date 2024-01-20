#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int max_pyramid_size(int n, int a[n]) {
  // 左から余分な石を取り除き、階段状にしていく
  for (int i = 1; i < n; i++)
    a[i] = min(a[i], a[i - 1] + 1);

  // 右からも同様に階段状にしていく
  for (int i = n - 2; i >= 0; i--)
    a[i] = min(a[i], a[i + 1] + 1);

  // a[i]はピラミッド型の配列になっているはず
  // for (int i = 0; i < n; i++)
  //   printf("%d ", a[i]);
  // printf("\n");

  // もっとも大きい値がピラミッドの頂点
  int top_height = 0;
  for (int i = 0; i < n; i++)
    top_height = max(top_height, a[i]);

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
