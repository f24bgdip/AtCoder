#include <stdio.h>
#include <string.h>

int main() {
  char S[200001];
  scanf("%s", S);

  char *src = S;
  char *dst = S;
  char *lastA = S;

  while (*src) {
    if (*src == 'A' && *(src + 1) == 'B' && *(src + 2) == 'C') {
      src += 3;
    } else {
      *dst++ = *src++;
    }

    if (*(dst - 1) == 'A')
      lastA = dst - 1;
    else if ((dst - lastA) > 2 && *lastA == 'A' && *(lastA + 1) == 'B' &&
             *(lastA + 2) == 'C') {
      dst = lastA;
    }
    printf("%s %ld:%c %ld:%c %ld:%c\n", S, dst - S, *dst, src - S, *src,
           lastA - S, *lastA);
  }

  *dst = '\0';

  printf("%s\n", S);

  return 0;
}
