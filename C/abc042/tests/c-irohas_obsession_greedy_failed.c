#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define TOTAL_NUMBERS 10

int check(int n, bool *is_dislikes) {
  int min_dislike_digit = -1;
  int digit_count = 0;
  while (n > 0) {
    int digit = n % 10;
    if (is_dislikes[digit]) {
      min_dislike_digit = digit_count;
    }
    n /= 10;
    digit_count++;
  }
  return min_dislike_digit;
}

int main() {
  int n, dislikes_k;
  if (scanf("%d %d", &n, &dislikes_k) != 2)
    return -1;

  bool is_dislikes[TOTAL_NUMBERS] = {false};
  for (int d, i = 0; i < dislikes_k; i++) {
    if (scanf("%d", &d) != 1)
      return -1;
    else
      is_dislikes[d] = true;
  }

  while (1) {
    int dislike_digit = check(n, is_dislikes);
    if (dislike_digit == -1) {
      break;
    } else {
      int increment = pow(10, dislike_digit);
      n = ((n / increment) + 1) * increment;
    }
  }

  printf("%d\n", n);

  return 0;
}
