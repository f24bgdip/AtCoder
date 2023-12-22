#include <limits.h>
#include <stdio.h>

int main() {
  int N, T;
  if (scanf("%d %d", &N, &T) != 2)
    return -1;

  int price;
  int min_price = 1e9;
  int max_profit = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &price) != 1)
      return -1;

    if (price == min_price)
      continue;
    else if (price < min_price) {
      min_price = price;
    } else {
      int profit = price - min_price;
      if (profit > max_profit) {
        max_profit = profit;
        count = 1;
      } else if (profit == max_profit) {
        count++;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
