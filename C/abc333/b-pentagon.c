#include <stdio.h>
#include <stdlib.h>

int is_equal(char a, char b) { return abs(a - b) == 1 || abs(a - b) == 4; }

int main() {
  char s1, s2, t1, t2;
  if (scanf(" %c%c", &s1, &s2) != 2)
    return -1;
  if (scanf(" %c%c", &t1, &t2) != 2)
    return -1;

  if (is_equal(s1, s2) == is_equal(t1, t2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
