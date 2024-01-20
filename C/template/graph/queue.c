/* This code based on the logic in the official explanation. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, m;
  if (scanf("%d %d", &n, &m) != 2)
    return -1;
  char s[n + 1], t[m + 1];
  if (scanf("%s %s", s, t) != 2)
    return -1;

  bool replaced[n - m + 1];
  memset(replaced, false, sizeof(replaced));
  int q[n - m + 1];
  int front = 0, rear = 0;

  for (int i = 0; i <= n - m + 1; i++) {
    bool can_replace = true;
    for (int j = 0; j < m; j++) {
      can_replace &= (s[i + j] == t[j]);
    }
    if (can_replace) {
      replaced[i] = true;
      q[rear++] = i;
    }
  }

  while (front < rear) {
    int pos = q[front++];
    for (int i = 0; i < m; i++)
      s[pos + i] = '#';
    for (int i = pos - m + 1; i <= pos + m - 1 && i <= n - m; i++) {
      if (i < 0 || replaced[i])
        continue;
      bool can_replace = true;
      for (int j = 0; j < m; j++) {
        can_replace &= (s[i + j] == '#' || s[i + j] == t[j]);
      }
      if (can_replace) {
        replaced[i] = true;
        q[rear++] = i;
      }
    }
  }

  printf("%s\n", (strcmp(s, (char *)memset(t, '#', n)) == 0) ? "Yes" : "No");

  return 0;
}