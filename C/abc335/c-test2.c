#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y;
} Position;

int main() {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  Position *parts = malloc(sizeof(Position) * (N + 1));
  Position *pre_position = malloc(sizeof(Position) * (N + 1));
  for (int i = 1; i <= N; i++) {
    parts[i].x = i;
    parts[i].y = 0;
    pre_position[i] = parts[i];
  }

  while (Q--) {
    int type;
    if (scanf("%d", &type) != 1)
      return -1;

    if (type == 1) {
      char C;
      if (scanf(" %c", &C) != 1)
        return -1;

      pre_position[1] = parts[1];

      if (C == 'U')
        parts[1].y++;
      else if (C == 'D')
        parts[1].y--;
      else if (C == 'R')
        parts[1].x++;
      else if (C == 'L')
        parts[1].x--;

      for (int i = 2; i <= N; i++) {
        Position temp = parts[i];
        parts[i] = pre_position[i - 1];
        pre_position[i] = temp;
      }
    } else if (type == 2) {
      int p;
      if (scanf("%d", &p) != 1)
        return -1;
      printf("%d %d\n", parts[p].x, parts[p].y);
    }
  }

  free(parts);
  free(pre_position);
  return 0;
}
