#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  bool a[n + 1];
  for (int i = 2; i <= n; i++)
    a[i] = true;
  a[0] = false, a[1] = false;

  for (int i = 2; i <= n; i++) {
    if (a[i] == false)
      continue;
    for (int mult = i * 2; mult <= n; mult += i) {
      a[mult] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (a[i])
      printf("%d ", i);
  }

  printf("\n");

  return 0;
}
