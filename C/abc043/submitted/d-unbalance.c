#include <stdio.h>
#include <string.h>

#define MAX 100000

void find_unbalanced_substring(char s[]) {
  int len = strlen(s);

  // Check for 2-char and 3-char pattern in the same loop
  for (int i = 0; i < len - 2; ++i) {
    if (s[i] == s[i + 1]) {
      printf("%d %d\n", i + 1, i + 2);
      return;
    }
    if (s[i] == s[i + 2]) {
      printf("%d %d\n", i + 1, i + 3);
      return;
    }
  }

  // Check the last 2-char pattern
  if (s[len - 2] == s[len - 1]) {
    printf("%d %d\n", len - 1, len);
    return;
  }

  // No unbalanced substring found
  printf("-1 -1\n");
}

int main() {
  char s[MAX + 1];

  if (scanf("%s", s) == 0)
    return -1;

  find_unbalanced_substring(s);

  return 0;
}
