#include <math.h>
#include <stdio.h>

int is_square(int n) {
  int root = sqrt(n);
  return root * root == n;
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

  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (is_square(A[i] * A[j])) {
        count++;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
