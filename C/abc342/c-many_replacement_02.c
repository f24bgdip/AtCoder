#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, Q;
  if (scanf("%d", &N) != 1)
    return -1;

  char S[N];
  if (scanf("%s", S) != 1)
    return -1;

  if (scanf("%d", &Q) != 1)
    return -1;

  char c[Q], d[Q];
  for (int i = 0; i < Q; i++) {
    if (scanf(" %c %c", &c[i], &d[i]) != 2)
      return -1;
  }

  // 置換を示す配列を用意し、初期値はその文字自身とする
  char replacements[26]; // 英小文字の数だけ
  int flag[26] = {0};
  for (int i = 0; i < 26; i++) {
    replacements[i] = 'a' + i; // 初期値は a, b, c, ... とする
  }

  for (int i = Q - 1; i >= 0; i--) {
    printf("Replacement: '%c' -> '%c'\n", c[i], d[i]); // デバッグ出力
    if (flag[c[i] - 'a'] == 0) {
      replacements[c[i] - 'a'] = d[i]; // c[i] の文字を d[i] で置換する
      flag[d[i] - 'a'] = 1;
    }
  }

  // 新しい文字列を構築する
  for (int i = 0; i < N; i++) {
    S[i] = replacements[S[i] - 'a'];
  }

  printf("%s\n", S);

  return 0;
}
