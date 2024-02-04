#include <stdio.h>
#include <string.h>

int main() {
  char S[101];

  if (scanf("%s", S) != 1)
    return -1;

  char *dot = strrchr(S, '.');

  if (dot != NULL) {
    printf("%s\n", dot + 1);
  } else {
    // error
  }

  return 0;
}
