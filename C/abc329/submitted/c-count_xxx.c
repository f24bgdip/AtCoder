#include <stdio.h>
#include <string.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  char S[N + 1];
  if (scanf("%s", S) != 1)
    return -1;

  int max[26] = {0};
  int len = 0;
  char c = 0;

  for (int i = 0; i < N; i++) {
    if (S[i] != c) {
      if (c != 0) {
        int index = c - 'a';
        if (len > max[index]) {
          max[index] = len;
        }
      }
      c = S[i];
      len = 1;
    } else {
      len++;
    }
  }

  int index = c - 'a';
  if (len > max[index]) {
    max[index] = len;
  }

  long long total = 0;
  for (int i = 0; i < 26; i++) {
    total += max[i];
  }

  printf("%lld\n", total);

  return 0;
}
