#include <stdio.h>
#include <string.h>

int main() {
  char s[100000 + 1];
  int score = 0;
  int g_cnt = 0;
  int p_cnt = 0;

  if (scanf("%s", s) != 1)
    return -1;

  int len = strlen(s);

  for (int i = 0; i < len; i++) {
    if (s[i] == 'g') {
      if (p_cnt < g_cnt) {
        score++;
        p_cnt++;
      } else {
        g_cnt++;
      }
    } else {
      if (p_cnt < g_cnt) {
        p_cnt++;
      } else {
        score--;
        g_cnt++;
      }
    }
  }

  printf("%d\n", score);

  return 0;
}
