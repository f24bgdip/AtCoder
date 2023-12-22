#include <stdio.h>

int main(void) {
  int n, s;
  if (scanf("%d %d", &n, &s) != 2)
    return -1;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) <= s)
        count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
