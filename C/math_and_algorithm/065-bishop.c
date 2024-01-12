#include <stdio.h>

int main(void) {
  long long H, W;
  if (scanf("%lld %lld", &H, &W) != 2)
    return -1;

  if (H == 1 || W == 1) {
    printf("1\n");
  } else {
    long long count = (H * W + 1) / 2;
    printf("%lld\n", count);
  }

  return 0;
}
