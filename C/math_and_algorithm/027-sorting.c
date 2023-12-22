#include <stdio.h>

void merge_ascending_order(int n, int a[]) {
  int l = n / 2;
  int L[l];
  for (int i = 0; i < l; i++)
    L[i] = a[0 + i];

  int r = n - l;
  int R[r];
  for (int i = 0; i < r; i++)
    R[i] = a[l + i];

  for (int i = 0, il = 0, ir = 0; i < n; i++) {
    if (ir >= r)
      // R is already empty.
      a[i] = L[il++];
    else if (il >= l)
      // L is already empty.
      a[i] = R[ir++];
    else {
      // ascendding order
      if (L[il] <= R[ir])
        a[i] = L[il++];
      else
        a[i] = R[ir++];
    }
  }
}

void merge_sort(int n, int a[]) {
  if (n > 1) {
    merge_sort(n / 2, &a[0]);
    merge_sort((n + 1) / 2, &a[n / 2]);
    merge_ascending_order(n, a);
  }
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
  }

  // sorting
  merge_sort(N, A);

  for (int i = 0; i < N; i++)
    printf("%d\n", A[i]);

  return 0;
}
