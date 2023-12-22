#include <stdio.h>
#include <string.h>

int main() {
  char S[200001];

  if (scanf("%s", S) != 1)
    return -1;

  char *src = S + 2;
  char *dst = S + 2;

  while (*src) {
    *dst = *src++;

    if (dst >= S + 2 && *(dst - 2) == 'A' && *(dst - 1) == 'B' && *dst == 'C') {
      dst -= 2;
    } else {
      dst++;
    }
  }

  *dst = '\0';
  printf("%s\n", S);

  return 0;
}
