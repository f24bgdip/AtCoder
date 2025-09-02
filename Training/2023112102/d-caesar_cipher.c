#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  char S[100000 + 1], T[100000 + 1];
  if (scanf("%s", S) != 1)
    return -1;
  if (scanf("%s", T) != 1)
    return -1;

  int len = strlen(S);
  int shift = (T[0] - S[0] + 26) % 26;
  bool can_solve = true;
  for (int i = 1; i < len; i++) {
    if ((T[i] - S[i] + 26) % 26 != shift) {
      can_solve = false;
    }
  }

  if (can_solve) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
