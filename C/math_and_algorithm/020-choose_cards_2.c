#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[100];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          for (int m = l + 1; m < N; m++) {
            if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
              count++;
            }
          }
        }
      }
    }
  }

  printf("%d\n", count);
  return 0;
}
