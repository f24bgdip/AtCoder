#include <stdio.h>

int min(int x, int y) { return (x < y) ? x : y; }

int max_servings(int n, int Q[], int recipe[]) {
  int max_servings = 1000000;
  for (int i = 0; i < n; ++i) {
    if (recipe[i] > 0) {
      max_servings = min(max_servings, Q[i] / recipe[i]);
    }
  }
  return max_servings;
}

int can_cook(int n, int Q[], int A[], int B[], int A_servings, int B_servings) {
  for (int i = 0; i < n; ++i) {
    if (Q[i] < A[i] * A_servings + B[i] * B_servings) {
      return 0;
    }
  }
  return 1;
}

int find_max_servings(int n, int Q[], int A[], int B[]) {
  int A_max = max_servings(n, Q, A);
  int B_max = max_servings(n, Q, B);
  int total_max = A_max + B_max;

  for (int A_servings = A_max; A_servings >= 0; --A_servings) {
    int B_servings = min(B_max, total_max - A_servings);
    if (can_cook(n, Q, A, B, A_servings, B_servings)) {
      return A_servings + B_servings;
    }
  }
  return 0;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int Q[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &Q[i]) != 1)
      return -1;
  }
  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  int B[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &B[i]) != 1)
      return -1;
  }

  printf("%d\n", find_max_servings(N, Q, A, B));

  return 0;
}
