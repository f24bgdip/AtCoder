// This is the sample of the bellow site.
// https://daeudaeu.com/c-decton/#program

#include <stdio.h>

/* unsigned long longのビット数 */
#define MAX_NUM_DIGITS 64

/* 係数を文字に変換するテーブル */
const char coef[36] = {'0', '2', '4', '6', '8'};

/* num文字の文字列の並びを逆順にする */
void reverse(char ans[], int num) {
  int i;
  char tmp;

  for (i = 0; i < num / 2; i++) {
    tmp = ans[i];
    ans[i] = ans[num - 1 - i];
    ans[num - 1 - i] = tmp;
  }
}

/* 10進数decをn進数に変換して結果をansに格納する */
void DectoN(char ans[], unsigned long long dec, unsigned int n) {

  unsigned int i;
  unsigned int digit_num;

  if (n > 36 || n < 2) {
    /* 対応しているのは2進数から36進数まで */
    return;
  }

  if (dec == 0) {
    // decが0の場合は直接 "0" を出力
    ans[0] = '0';
    ans[1] = '\0';
    return;
  }
  
  i = 0;
  while (dec > 0) {
    /* i桁目の係数を求める */
    digit_num = dec % n;

    /* 文字に変換 */
    ans[i] = coef[digit_num];

    /* n進数で１桁分桁下げ */
    dec = dec / n;

    /* 次に求める係数の桁 */
    i++;
  }

  /* 最後にヌル文字をつける */
  ans[i] = '\0';

  /* 文字列の並びを逆順にする */
  reverse(ans, i);
}

int main(void) {

  char ans[MAX_NUM_DIGITS + 1];
  unsigned long long dec;
  unsigned int n;

  if (scanf("%llu", &dec) != 1)
    return -1;

  dec--;
  DectoN(ans, dec, 5);
  printf("%s\n", ans);

  return 0;
}
