#include <stdio.h>

int main() {
  int A, B, D;
  if (scanf("%d %d %d", &A, &B, &D) != 3)
    return -1;

  for (int i = A; i <= B; i += D) {
    printf("%d ", i);
  }

  return 0;
}
