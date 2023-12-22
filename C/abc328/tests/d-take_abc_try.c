#include <stdio.h>
#include <string.h>

int main() {
  char S[200001];
  char tmp[200001];

  if (scanf("%s", S) != 1)
    return -1;

  char *src = S;
  char *dst = S;
  char *watch = S;

  while (*src) {
    // 前方走査
    if (*src == 'A' && *(src + 1) == 'B' && *(src + 2) == 'C') {
      src += 3;
    } else {
      *dst = *src++;
      // 後方走査
      if (dst - S > 2) {
        watch = dst - 2;
        if (*watch == 'A' && *(watch + 1) == 'B' && *(watch + 2) == 'C') {
          dst = watch;
        } else {
          *dst++;
        }
      }else{
        *dst++;
      }
    }

    strcpy(tmp, S);
    tmp[(dst - S)] = '\0';
    printf("%s %ld:%c %ld:%c %ld:%c\n", tmp, dst - S, *dst, src - S, *src,
           watch - S, *watch);
  }

  *dst = '\0'; // 文字列の終端を設定

  printf("%s\n", S);
  return 0;
}
