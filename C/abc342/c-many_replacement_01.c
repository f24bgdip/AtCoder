#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, Q;
  if (scanf("%d", &N) != 1)
    return -1;

  char *S = (char *)malloc((N + 1) * sizeof(char));
  if (scanf("%s", S) != 1)
    return -1;

  if (scanf("%d", &Q) != 1)
    return -1;

  char *c = (char *)malloc(Q * sizeof(char));
  char *d = (char *)malloc(Q * sizeof(char));

  for (int i = 0; i < Q; i++) {
    if (scanf(" %c %c", &c[i], &d[i]) != 2)
      return -1;
    for (int j = 0; j < N; j++) {
      if (S[j] == c[i]) {
        S[j] = d[i];
      }
    }
  }

  printf("%s\n", S);

  free(S);
  free(c);
  free(d);

  return 0;
}
