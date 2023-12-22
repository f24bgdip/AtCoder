#include <stdio.h>

int main(void) {
  char s[100 + 1];

  if (scanf("AtCoder %s Contest", s) != 1)
    return -1;

  printf("A%cC", s[0]);

  return 0;
}
