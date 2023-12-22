#include <stdio.h>
#include <string.h>

void main(void) {
  unsigned char s[101];
  unsigned int c, l = 0;
  int i, j;

  if (scanf("%s", s) == 0)
    return;

  l = strlen(s);

  if (l % 2)
    goto no;

  for (i = 0; i < l; i++) {
    if (*(s + i) == 'X')
      break;
    else {
      c = 1;
    }

    for (j = i + 1; j <= l; j++) {
      if (*(s + i) == *(s + j)) {
        *(s + j) = 'X';
        c++;
      }
    }
    if (c % 2)
      goto no;
  }

  printf("Yes");

  return;

no:
  printf("No");

  return;
}