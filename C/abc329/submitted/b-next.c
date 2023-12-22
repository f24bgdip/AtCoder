#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int max1 = 0;
  int max2 = 0;

  for (int i = 0; i < N; i++) {
    int A;
    if (scanf("%d", &A) != 1)
      return -1;

    if (A > max1) {
      max2 = max1;
      max1 = A;
    } else if (A > max2 && A < max1) {
      max2 = A;
    }
  }

  printf("%d\n", max2);

  return 0;
}
