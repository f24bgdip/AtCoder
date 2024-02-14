#include <stdio.h>
#include <stdlib.h>

int main() {
  int Q;
  if (scanf("%d", &Q) != 1)
    return -1;

  int *A = NULL;
  int size = 0;

  for (int i = 0; i < Q; ++i) {
    int q_type, x;
    if (scanf("%d", &q_type) != 1)
      return -1;

    if (q_type == 1) {
      if (scanf("%d", &x) != 1)
        return -1;
      size++;
      A = (int *)realloc(A, size * sizeof(int));
      A[size - 1] = x;
    } else if (q_type == 2) {
      int k;
      if (scanf("%d", &k) != 1)
        return -1;
      printf("%d\n", A[size - k]);
    }
  }
  free(A);

  return 0;
}
