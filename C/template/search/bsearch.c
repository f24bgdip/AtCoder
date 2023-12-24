#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int search(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x)
      return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  qsort(A, N, sizeof(int), cmp);

  int count = 0;
  for (int i = 0; i < N; i++) {
    int complement = 100000 - A[i];
    if (search(A, i + 1, N - 1, complement) != -1) {
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}
