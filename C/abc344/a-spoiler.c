#include <stdio.h>

int main() {
  char s[101];
  if (scanf("%s", s) != 1)
    return -1;

  int i = 0;
  while (s[i] != '|') {
    putchar(s[i]);
    i++;
  }

  i++;
  while (s[i] != '|') {
    i++;
  }

  i++;
  while (s[i] != '\0') {
    putchar(s[i]);
    i++;
  }

  return 0;
}
