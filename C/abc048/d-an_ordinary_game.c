#include <stdio.h>
#include <string.h>

int main() {
  char s[100000 + 1];
  if (scanf("%s", s) != 1)
    return -1;

  int len = strlen(s);
  if (s[0] == s[len - 1]) {
    if (len % 2 == 0) {
      printf("First\n");
    } else {
      printf("Second\n");
    }
  } else {
    if (len % 2 == 0) {
      printf("Second\n");
    } else {
      printf("First\n");
    }
  }

  return 0;
}
