#include <stdio.h>

int main(void) {
  int H, W;
  if (scanf("%d %d", &H, &W) != 2)
    return -1;

  char image[H][W + 1];

  for (int i = 0; i < H; i++) {
    if (scanf("%s", image[i]) != 1)
      return -1;
  }

  for (int i = 0; i < H; i++) {
    printf("%s\n", image[i]);
    printf("%s\n", image[i]);
  }

  return 0;
}
