#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char S[100 + 1];
  if (scanf("%s", S) != 1)
    return -1;

  if (!isupper(S[0])) {
    printf("No\n");
    return 0;
  }

  if (strlen(S) > 1) {
    for (int i = 1; S[i]; i++) {
      if (islower(S[i]))
        continue;
      else {
        printf("No\n");
        return 0;
      }
    }
  }

  printf("Yes\n");
  return 0;
}
