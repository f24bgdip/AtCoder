#include <stdio.h>

void main(void) {
  unsigned int period, xday, standard_price, discounted_price, total_fee = 0;
  int i;

  if (scanf("%u", &period) == 0)
    return;

  if (scanf("%u", &xday) == 0)
    return;

  if (scanf("%u", &standard_price) == 0)
    return;

  if (scanf("%u", &discounted_price) == 0)
    return;

  for (i = 0; i < period; i++) {
    if (i < xday) {
      total_fee += standard_price;
    } else {
      total_fee += discounted_price;
    }
  }

  printf("%d", total_fee);

  return;
}