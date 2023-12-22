#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  char S[250001];

  if (scanf("%d", &N) != 1)
    return -1;
  if (scanf("%s", S) != 1)
    return -1;

  long long inversion_cnt = 0;
  int greater_cnt = 0;

  for (int i = 0; i < N - 1; i++) {
    if (S[i] == '>') {
      greater_cnt++;
    } else {
      inversion_cnt += (long long)greater_cnt * (greater_cnt + 1) / 2;
      greater_cnt = 0;
    }
  }

  inversion_cnt += (long long)greater_cnt * (greater_cnt + 1) / 2;

  printf("%lld\n", inversion_cnt);

  return 0;
}
