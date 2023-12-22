// failed test case
// 15 3
// 1 2 3
// 40

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_NUMBERS 10
#define MAX_DIGITS 6

int main(void) {
  int n, k;
  if (scanf("%d %d", &n, &k) != 2)
    return -1;

  bool is_dislike[TOTAL_NUMBERS] = {false};
  for (int d, i = 0; i < k; i++) {
    if (scanf("%d", &d) != 1)
      return -1;
    else
      is_dislike[d] = true;
  }

  int like[TOTAL_NUMBERS - k];
  for (int i = 0, j = 0; i < TOTAL_NUMBERS; i++) {
    if (!is_dislike[i])
      like[j++] = i;
  }

  // MAX_DIGITS + NULL終端文字
  char *str_num = (char *)calloc(MAX_DIGITS + 1, sizeof(char));
  if (str_num == NULL) {
    return -1;
  }

  int ret = snprintf(str_num, MAX_DIGITS + 1, "%d", n);
  if (ret < 0 || ret > MAX_DIGITS)
    goto fail;

  // 各桁を調べる前にneeds_carryを1にセットして、その桁で繰り上がりが不要であれば0に戻します。
  // このようにすることで、最終的にneeds_carryが1のままであれば、新しい桁を追加する必要があると判断できます。
  int len = strlen(str_num);
  int needs_carry = 0;
  for (int i = len - 1; i >= 0; i--) {
    int digit = (str_num[i] - '0') + needs_carry;
    needs_carry = 1;
    for (int j = 0; j < TOTAL_NUMBERS - k; j++) {
      if (like[j] >= digit) {
        // overwrite
        str_num[i] = like[j] + '0';
        needs_carry = 0;
        break;
      }
    }
    if (needs_carry == 1) {
      str_num[i] = like[0] + '0';
    }
  }

  // answer
  if (needs_carry) {
    int i;
    for (i = 0; i < TOTAL_NUMBERS - k; i++)
      if (like[i] > 0)
        break;
    printf("%c%s\n", like[i] + '0', str_num);
  } else
    printf("%s\n", str_num);

  // pass
  free(str_num);
  return 0;

fail:
  // fail
  free(str_num);
  return -1;
}