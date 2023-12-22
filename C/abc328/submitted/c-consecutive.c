#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  char S[N + 1];
  scanf("%s", S);

  int pair[N + 1];
  memset(pair, 0, sizeof(pair));

  for (int i = 1; i < N; i++) {
    pair[i + 1] = pair[i] + (S[i] == S[i - 1]);
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);

    printf("%d\n", pair[r] - pair[l]);
  }

  return 0;
}
