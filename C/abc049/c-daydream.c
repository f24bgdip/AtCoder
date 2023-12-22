#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char S[100000 + 1];
  if (scanf("%s", S) != 1)
    return -1;

  int len = strlen(S);
  bool can_form = true;

  while (len > 0 && can_form) {
    if (len >= 7 && strncmp(S + len - 7, "dreamer", 7) == 0) {
      len -= 7;
    } else if (len >= 6 && strncmp(S + len - 6, "eraser", 6) == 0) {
      len -= 6;
    } else if (len >= 5 && strncmp(S + len - 5, "dream", 5) == 0) {
      len -= 5;
    } else if (len >= 5 && strncmp(S + len - 5, "erase", 5) == 0) {
      len -= 5;
    } else {
      can_form = false;
    }
  }

  if (can_form) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
