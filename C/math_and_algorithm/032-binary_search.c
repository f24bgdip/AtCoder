#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
long long int llmin(long long int a, long long int b) {
  return (a < b) ? a : b;
}
long long int llmax(long long int a, long long int b) {
  return (a > b) ? a : b;
}

int cmp_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(void) {
  int N, X;
  if (scanf("%d %d", &N, &X) != 2)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  qsort(A, N, sizeof(int), cmp_int);

  bool match = false;
  int low = 0, high = N - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (A[mid] == X) {
      match = true;
      break;
    } else if (A[mid] > X) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  printf("%s\n", match ? "Yes" : "No");

  return 0;
}
