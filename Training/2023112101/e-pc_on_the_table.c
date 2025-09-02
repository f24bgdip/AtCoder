#include <stdio.h>
#include <string.h>

#define MAX_H 100
#define MAX_W 100

int main() {
  int H, W;
  if (scanf("%d %d", &H, &W) != 2)
    return -1;

  char S[MAX_H][MAX_W + 1];
  for (int i = 0; i < H; i++) {
    if (scanf("%s", S[i]) != 1)
      return -1;
    for (int j = 0; j < W - 1; j++) {
      if (S[i][j] == 'T' && S[i][j + 1] == 'T') {
        S[i][j] = 'P';
        S[i][j + 1] = 'C';
        j++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    printf("%s\n", S[i]);
  }

  return 0;
}
