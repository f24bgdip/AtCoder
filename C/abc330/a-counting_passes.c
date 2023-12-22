#include <stdio.h>

int main() {
  int N, L, i, count = 0;
  if (scanf("%d %d", &N, &L) != 2)
    return -1;

  int score;
  for (i = 0; i < N; i++) {
    if (scanf("%d", &score) != 1)
      return -1;

    if (score >= L) {
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}
