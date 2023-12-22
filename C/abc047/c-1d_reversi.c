#include <stdio.h>
#include <string.h>

int main() {
  char s[100000 + 1];
  if (scanf("%s", s) != 1)
    return -1;

  int transitions = 0;
  int length = strlen(s);

  char color = s[0];

  for (int i = 1; i < length; i++) {
    if (s[i] != color) {
      transitions++;
      color = s[i];
    }
  }

  printf("%d\n", transitions);

  return 0;
}
