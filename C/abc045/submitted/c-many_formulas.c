#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char S[11];
  if (scanf("%s", S) != 1)
    return -1;

  int len = strlen(S);
  int cases = 1 << (len - 1);

  long long total = 0;
  for (int i = 0; i < cases; i++) {
    long long sum = 0, num = 0;
    for (int j = 0; j < len; j++) {
      num = num * 10 + (S[j] - '0');
      int ins_plus = i & (1 << j);
      if (ins_plus || j == len - 1) {
        sum += num;
        num = 0;
      }
    }
    total += sum;
  }

  printf("%lld\n", total);

  return 0;
}
