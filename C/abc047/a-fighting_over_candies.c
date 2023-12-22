#include <stdio.h>

int main() {
  int a, b, c;

  if (scanf("%d %d %d", &a, &b, &c) != 3)
    return -1;

  if (a == b + c || b == a + c || c == a + b) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
