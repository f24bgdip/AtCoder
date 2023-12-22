#include <stdio.h>

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  int count[4] = {0};
  for (int i = 0; i < n; i++) {
    int price;
    scanf("%d", &price);
    count[price / 100 - 1]++;
  }

  long long ways =
      (long long)count[0] * count[3] + (long long)count[1] * count[2];
  printf("%lld\n", ways);

  return 0;
}
