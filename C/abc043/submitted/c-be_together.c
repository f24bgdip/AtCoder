#include <math.h>
#include <stdio.h>

int main() {
  int n, sum = 0;
  scanf("%d", &n);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  int x = round((double)sum / n);
  int cost = 0;
  for (int i = 0; i < n; i++) {
    cost += pow(a[i] - x, 2);
  }

  printf("%d\n", cost);
  return 0;
}
