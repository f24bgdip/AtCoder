#include <stdio.h>

int main(void) {
  int n, s;
  if (scanf("%d %d", &n, &s) != 2)
    return -1;
  int a[n];
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) != 1)
      return -1;
  }
  for (long long pattern = 0; pattern < (1 << n); pattern++) {
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (pattern & (1 << i)) {
        sum += a[i];
      }
    if (sum == s) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
