#include <stdio.h>

int main() {
  long long N;
  if (scanf("%lld", &N) != 1)
    return -1;

  if (N % 2 == 0) {
    printf("Yes\n");
  } else {
    // 奇数のグリッドでは、同じマスを2回通ることなく全てのマスを通過することは不可能
    printf("No\n");
  }

  return 0;
}
