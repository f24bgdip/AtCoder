#include <stdio.h>

int main() {
  char S[4];
  int a, b, ans;

  if (scanf("%3s", S) != 1)
    return -1;

  a = S[0] - '0';
  b = S[2] - '0';

  ans = a * b;

  printf("%d\n", ans);

  return 0;
}
