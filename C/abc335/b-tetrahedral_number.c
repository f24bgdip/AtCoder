#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N - x; y++) {
      for (int z = 0; z <= N - x - y; z++) {
        printf("%d %d %d\n", x, y, z);
      }
    }
  }

  return 0;
}
