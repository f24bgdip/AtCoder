#include <stdio.h>

int main() {
  int V, A, B, C;

  if (scanf("%d %d %d %d", &V, &A, &B, &C) != 4)
    return -1;

  int total = A + B + C;
  V %= total;

  if (V < A) {
    printf("F\n");
  } else if (V < A + B) {
    printf("M\n");
  } else {
    printf("T\n");
  }

  return 0;
}
