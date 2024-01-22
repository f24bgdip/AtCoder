#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int team_t_total = 0, team_a_total = 0;
  for (int i = 0; i < N; i++) {
    int X, Y;
    if (scanf("%d %d", &X, &Y) != 2)
      return -1;
    team_t_total += X;
    team_a_total += Y;
  }

  if (team_t_total > team_a_total) {
    printf("Takahashi\n");
  } else if (team_t_total < team_a_total) {
    printf("Aoki\n");
  } else {
    printf("Draw\n");
  }

  return 0;
}
