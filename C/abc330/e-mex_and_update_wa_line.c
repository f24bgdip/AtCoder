#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200001

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  int A[N], freq[MAX_N] = {0}, mex = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (A[i] < MAX_N) {
      freq[A[i]]++;
    }
  }

  while (freq[mex])
    mex++;

  for (int q = 0; q < Q; q++) {
    int i, x;
    scanf("%d %d", &i, &x);

    i--;

    if (A[i] < MAX_N) {
      freq[A[i]]--;
      if (freq[A[i]] == 0 && mex > A[i])
        mex = A[i];
    }

    A[i] = x;

    if (A[i] < MAX_N) {
      freq[A[i]]++;
      if (freq[A[i]] == 1 && mex == A[i]) {
        while (freq[mex])
          mex++;
      }
    }

    printf("%d\n", mex);
  }

  return 0;
}
