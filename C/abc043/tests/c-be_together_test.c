#include <math.h>
#include <stdio.h>

int main(void) {
  int n;

  if (scanf("%d", &n) == 0)
    return -1;

  int a[n], sum = 0;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) == 0)
      return -1;

    sum += a[i];
  }

  printf("sum=%d\n", sum);

  int x = (int)round((double)sum / n);
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow((a[i] - x), 2);
  }

  printf("x=%d ans=%d\n", x, sum);

  return 0;
}
