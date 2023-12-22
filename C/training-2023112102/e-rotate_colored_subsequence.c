#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  char S[N + 1];
  if (scanf("%s", S) != 1)
    return -1;

  int C[N];
  int **positions = (int **)malloc(M * sizeof(int *));
  int *sizes = (int *)calloc(M, sizeof(int));
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &C[i]) != 1)
      return -1;

    int color = C[i] - 1;
    sizes[color]++;
    positions[color] =
        (int *)realloc(positions[color], sizes[color] * sizeof(int));
    positions[color][sizes[color] - 1] = i;
  }

  for (int i = 0; i < M; i++) {
    if (sizes[i] <= 1)
      continue;

    char last = S[positions[i][sizes[i] - 1]];
    for (int j = sizes[i] - 1; j > 0; j--) {
      S[positions[i][j]] = S[positions[i][j - 1]];
    }
    S[positions[i][0]] = last;
  }

  printf("%s\n", S);

  for (int i = 0; i < M; i++) {
    free(positions[i]);
  }
  free(positions);
  free(sizes);

  return 0;
}
