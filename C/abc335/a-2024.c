#include <stdio.h>
#include <string.h>

int main(void) {
  char S[100 + 1];
  if (scanf("%s", S) != 1)
    return -1;

  int len = strlen(S);
  S[len - 1] = '4';
  printf("%s\n", S);

  return 0;
}
