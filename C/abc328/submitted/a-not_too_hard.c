#include <stdio.h>

int main() {
  int N, X;
  scanf("%d %d", &N, &X);

  int total_score = 0;
  for (int i = 0; i < N; i++) {
    int score;
    scanf("%d", &score);

    if (score <= X) {
      total_score += score;
    }
  }

  printf("%d\n", total_score);

  return 0;
}
