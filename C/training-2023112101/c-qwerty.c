#include <stdio.h>

int main() {
  int P;
  char S[26 + 1] = {0};

  for (int i = 0; i < 26; i++) {
    if (scanf("%d", &P) != 1)
      break;

    S[i] = 'a' + P - 1;
  }

  printf("%s\n", S);

  return 0;
}
