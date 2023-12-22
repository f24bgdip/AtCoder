#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  char S[200001];
  scanf("%s", S);

  bool found;
  do {
    char *src = S;
    char *dst = S;
    found = false;

    while (*src) {
      if (*src == 'A' && *(src + 1) == 'B' && *(src + 2) == 'C') {
        src += 3;
        found = true;
      } else {
        *dst++ = *src++;
      }
    }
    *dst = '\0';
  } while (found);

  printf("%s\n", S);

  return 0;
}
