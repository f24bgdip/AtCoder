#include <stdio.h>
#include <string.h>

int main() {
  char S[101];
  if (scanf("%s", S) != 1)
    return -1;

  int phase = 0;
  int flag = 0;

  // まず、1文字目が何であるかを把握します。
  if (S[0] == 'A') {
    flag += 1;
    phase = 0;
  } else if (S[0] == 'B')
    phase = 1;
  else if (S[0] == 'C')
    phase = 2;

  // Aである場合、拡張A文字列と拡張ABC文字列の可能性
  if (phase == 0) {
    for (int i = 1; i < strlen(S); i++) {
      if (phase == 0 && S[i] == 'A')
        continue;
      if (phase == 0 && S[i] == 'B') {
        phase = 1;
        flag += 2;
        continue;
      }
      if (phase == 1 && S[i] == 'B')
        continue;
      if (phase == 1 && S[i] == 'C') {
        flag += 4;
        phase = 2;
        continue;
      }
      if (phase == 2 && S[i] == 'C')
        continue;

      printf("No\n");
      return 0;
    }
    if (flag != 1 && flag != 7) {
      printf("No\n");
      return 0;
    }
    // Bの場合、拡張B文字列のみYesでそれ以外はNo
  } else if (phase == 1) {
    for (int i = 1; i < strlen(S); i++) {
      if (phase == 1 && S[i] == 'B')
        continue;
      printf("No\n");
      return 0;
    }
    // Cの場合、拡張C文字列のみYes、それ以外はNo
  } else if (phase == 2) {
    for (int i = 1; i < strlen(S); i++) {
      if (phase == 2 && S[i] == 'C')
        continue;
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}