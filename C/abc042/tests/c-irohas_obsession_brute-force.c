#include <stdbool.h>
#include <stdio.h>

bool check(int n, int dislike[], int k) {
  while (n > 0) {
    int digit = n % 10;
    for (int i = 0; i < k; i++) {
      if (digit == dislike[i]) {
        return false;
      }
    }
    n /= 10;
  }

  return true;
}

int main() {
  int n, k;
  if(scanf("%d %d", &n, &k) != 2)
    return -1;

  int dislike[k];
  for (int i = 0; i < k; i++) {
    if(scanf("%d", &dislike[i]) != 1)
      return -1;
  }

  while (1) {
    if (check(n, dislike, k)) {
      printf("%d\n", n);
      break;
    }
    n++;
  }

  return 0;
}
