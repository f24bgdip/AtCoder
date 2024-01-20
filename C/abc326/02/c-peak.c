#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

// ascending order
int cmp_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(void) {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  qsort(A, N, sizeof(int), cmp_int);

  int max_gifts = 0;
  int left = 0, right = 0;

  while (right < N) {
    // 現在の区間が M 以内の場合、含まれる
    // 現在の区間が M より大きい場合、含まれない
    if (A[right] - A[left] < M) {
      // 最大値を更新
      max_gifts = max(max_gifts, right - left + 1);
      // 区間を広げる
      right++;
    } else {
      // 区間を縮める
      left++;
    }
  }
  printf("%d\n", max_gifts);

  return 0;
}
