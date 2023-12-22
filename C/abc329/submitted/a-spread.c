#include <stdio.h>
#include <string.h>

int main() {
  char S[100 + 1];

  if (scanf("%s", S) != 1)
    return -1;

  int len = strlen(S);

  for (int i = 0; i < len - 1; i++) {
    printf("%c ", S[i]);
  }

  printf("%c\n", S[len - 1]);

  return 0;
}
