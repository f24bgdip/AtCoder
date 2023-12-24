#include <stdio.h>

int main(void) {
  int A, B;
  if (scanf("%d %d", &A, &B) != 2)
    return -1;

  if (A > B)
    printf("Bat\n");
  else
    printf("Glove\n");

  return 0;
}
