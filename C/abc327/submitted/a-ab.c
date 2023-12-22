#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  char s[n + 1];
  if (scanf("%s", s) != 1)
    return -1;

  bool ans = false;
  for (int i = 0; i < n; i++) {
    if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a')) {
      ans = true;
      break;
    }
  }

  if (ans) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
