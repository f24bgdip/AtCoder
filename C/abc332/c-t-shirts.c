#include <stdio.h>
#include <string.h>

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  char S[N + 1];
  if (scanf("%s", S) != 1)
    return -1;

  int new_logo_shirts = 0;
  int logo_shirts = 0;
  int dirty_logo_shirts = 0;
  int plain_shirts = M;
  int dirty_plain_shirts = 0;
  for (int i = 0; i < N; i++) {
    switch (S[i]) {
    case '0':
      // no plan
      logo_shirts += dirty_logo_shirts;
      dirty_logo_shirts = 0;
      plain_shirts += dirty_plain_shirts;
      dirty_plain_shirts = 0;
      break;
    case '1':
      // dinner
      if (plain_shirts > 0) {
        plain_shirts--;
        dirty_plain_shirts++;
      } else if (logo_shirts > 0) {
        logo_shirts--;
        dirty_logo_shirts++;
      } else {
        new_logo_shirts++;
        dirty_logo_shirts++;
      }
      break;
    case '2':
      // event
      if (logo_shirts > 0) {
        logo_shirts--;
        dirty_logo_shirts++;
      } else {
        new_logo_shirts++;
        dirty_logo_shirts++;
      }
      break;
    }
  }
  printf("%d\n", new_logo_shirts);

  return 0;
}
