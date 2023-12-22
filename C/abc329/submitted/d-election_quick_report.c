#include <stdio.h>

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  int votes[N + 1];
  for (int i = 0; i <= N; i++) {
    votes[i] = 0;
  }

  int max = 0;
  int winner = 1;
  for (int i = 0; i < M; i++) {
    int num;
    if (scanf("%d", &num) != 1)
      return -1;

    votes[num]++;
    if ((max == votes[num] && winner > num) || max < votes[num]) {
      max = votes[num];
      winner = num;
    }
    printf("%d\n", winner);
  }

  return 0;
}
