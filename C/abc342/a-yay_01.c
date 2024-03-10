#include <stdio.h>
#include <string.h>

int main() {
  char S[101];
  if (scanf("%s", S) != 1)
    return -1;

  int length = strlen(S);
  char s1 = S[0], s2 = S[1], s3 = '\0';
  int i;
  for (i = 2; i < length; i++) {
    if (s1 != s2 && s2 == s3) {
      printf("1\n");
      break;
    } else if (s1 != s2 && s1 == s3) {
      printf("2\n");
      break;
    } else if (s1 == s2 && s1 != s3) {
      printf("%d\n", i);
      break;
    }
    s3 = S[i];
  }

  return 0;
}
