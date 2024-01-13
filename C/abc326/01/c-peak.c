#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  qsort(A, N, sizeof(int), compare);

  int max_count = 0;
  int j = 0;
  for (int i = 0; i < N; i++) {
    while (j < N && A[j] - A[i] < M) {
      j++;
    }
    if (j - i > max_count) {
      max_count = j - i;
    }
  }

  printf("%d\n", max_count);

  return 0;
}
