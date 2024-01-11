#include <stdio.h>
#include <string.h>

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  char S[N + 1];
  if (scanf("%s", S) != 1)
    return -1;

  const char str[] = "na";
  char *start = S;
  char *found = strstr(start, str);
  while (*start != '\0' && found != NULL) {
    printf("%.*snya", (int)(found - start), start);
    start = found + 2;
    found = strstr(start, str);
  }
  printf("%s\n", start);

  return 0;
}
