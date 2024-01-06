#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y, move;
} Part;

int main() {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  Part *parts = malloc(sizeof(Part) * (N + 1));
  for (int i = 1; i <= N; i++) {
    parts[i].x = i;
    parts[i].y = 0;
    parts[i].move = 0;
  }

  int move_count = 0;
  while (Q--) {
    int type;
    if (scanf("%d", &type) != 1)
      return -1;

    if (type == 1) {
      char C;
      if (scanf(" %c", &C) != 1)
        return -1;
      move_count++;
      if (C == 'U')
        parts[1].y++;
      else if (C == 'D')
        parts[1].y--;
      else if (C == 'R')
        parts[1].x++;
      else if (C == 'L')
        parts[1].x--;

      parts[1].move = move_count;
    } else if (type == 2) {
      int p;
      if (scanf("%d", &p) != 1)
        return -1;

      for (int i = 2; i <= p; i++) {
        if (parts[i].move < parts[i - 1].move) {
          parts[i] = parts[i - 1];
          parts[i].move = parts[i - 1].move;
        }
      }
      printf("%d %d\n", parts[p].x, parts[p].y);
    }
  }

  free(parts);
  return 0;
}
