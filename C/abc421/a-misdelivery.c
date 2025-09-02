/*
キーワード
配列操作, 検索
*/
#include <stdio.h>
#include <string.h>

int main(void) {
  int N;
  scanf("%d", &N);

  char s[100][10 + 1];
  for (int i = 0; i < N; ++i) {
    scanf("%10s", s[i]);
  }

  int X;
  char Y[10 + 1];
  scanf("%d %10s", &X, Y);

  int i = X - 1;
  if (strcmp(s[i], Y) == 0)
    puts("Yes");
  else
    puts("No");

  return 0;
}
