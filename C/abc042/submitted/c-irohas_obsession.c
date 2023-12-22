#include <stdbool.h>
#include <stdio.h>

#define TOTAL_NUMBERS 10
#define MAX_DIGITS 6

bool check(int n, bool *is_dislikes) {
  while (n > 0) {
    int digit = n % 10;
    if (is_dislikes[digit])
      return false;
    n /= 10;
  }
  return true;
}

int main() {
  int n, dislikes_k;
  if (scanf("%d %d", &n, &dislikes_k) != 2)
    return -1;

  bool is_dislikes[TOTAL_NUMBERS + 1] = {false};
  for (int d, i = 0; i < dislikes_k; i++) {
    if (scanf("%d", &d) != 1)
      return -1;
    else
      is_dislikes[d] = true;
  }

  while (1) {
    if (check(n, is_dislikes)) {
      break;
    } else {
      int digit = n % 10;
      do {
        digit++;
      } while (is_dislikes[digit]);
      n = (n / 10) * 10 + digit;
    }
  }

  printf("%d\n", n);

  return 0;
}