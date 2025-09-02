#include <stdio.h>
#include <string.h>

int main() {
  int N, K;
  if (scanf("%d %d", &N, &K) != 2)
    return -1;

  char S[101];
  if (scanf("%s", S) != 1)
    return -1;

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') {
      count++;
      if (count > K) {
        S[i] = 'x';
      }
    }
  }

  printf("%s\n", S);

  return 0;
}
