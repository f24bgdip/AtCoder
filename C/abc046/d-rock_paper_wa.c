#include <stdio.h>
#include <string.h>

int main() {
  char s[100001];
  int score = 0;
  int countG = 0;

  // 入力を受け取る
  scanf("%s", s);
  int len = strlen(s);

  for (int i = 0; i < len; i++) {
    if (s[i] == 'g') {
      if (countG > 0) {
        // パーを出して得点を得る
        score++;
        countG--;
      } else {
        // グーを出す
        countG++;
      }
    } else { // s[i] == 'p'
      // グーを出して得点を失わない
      countG++;
    }
  }

  // 得点を出力
  printf("%d\n", score);

  return 0;
}
