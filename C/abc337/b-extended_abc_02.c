#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_extended(const char *str) {
  int i = 0;
  int n = strlen(str);

  // A の部分を確認
  while (i < n && str[i] == 'A') {
    i++;
  }

  // B の部分を確認
  while (i < n && str[i] == 'B') {
    i++;
  }

  // C の部分を確認
  while (i < n && str[i] == 'C') {
    i++;
  }

  // 文字列の最後まで到達したかを確認
  return i == n;
}

int main() {
  char str[101];
  if (scanf("%s", str) != 1)
    return -1;

  if (is_extended(str)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
