#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[200000] = {0};
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i] + A[j] == 100000) {
        count++;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}
