#include <stdio.h>
#include <stdlib.h>

/**
   Read a number, N, from standard input and print the
   permutations.
 */

void print(const int *v, const int size, char a[size]) {
  if (v != 0) {
    for (int i = 0; i < size; i++) {
      printf("%4d", a[v[i]]);
    }
    printf("\n");
  }
} // print

void swap(int *v, const int i, const int j) {
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}

void rotateLeft(int *v, const int start, const int n) {
  int tmp = v[start];
  for (int i = start; i < n - 1; i++) {
    v[i] = v[i + 1];
  }
  v[n - 1] = tmp;
} // rotateLeft

void permute(int *v, const int start, const int n, char a[n]) {
  print(v, n, a);
  if (start < n) {
    int i, j;
    for (i = n - 2; i >= start; i--) {
      for (j = i + 1; j < n; j++) {
        swap(v, i, j);
        permute(v, i + 1, n);
      } // for j
      rotateLeft(v, i, n);
    } // for i
  }
} // permute

void init(int *v, int N) {
  for (int i = 0; i < N; i++) {
    v[i] = i + 1;
  }
} // init

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;
  int s[n];
  if (scanf("%s", s) != 1)
    return -1;

  int *v = (int *)malloc(sizeof(int) * n);
  init(v, n);
  permute(v, 0, n, s);
  free(v);

  return 0;
}