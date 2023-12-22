#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++)
    A[i] = 0;

  int L, R, X;
  for (int i = 0; i < Q; i++) {
    if (scanf("%d %d %d", &L, &R, &X) != 3)
      return -1;
    for (int j = L - 1; j < R; j++) {
      A[j] += X;
    }
  }

  char s[N];
  for (int i = 0; i < N - 1; i++)
    if (A[i] > A[i + 1])
      printf(">");
    else if (A[i] < A[i + 1])
      printf("<");
    else
      printf("=");

  return 0;
}
